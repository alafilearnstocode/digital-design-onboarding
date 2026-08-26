# Median Pixel Filter Checkpoints

This breaks the median pixel filter project into smaller checkpoints so nobody has to jump straight into the full `median_filter` module with no clue what's going on.

The point is to understand how pixels move through hardware one clock cycle at a time.

## How To Use This

For each checkpoint:

1. Read what the checkpoint is asking for.
2. Fill in only that small part of the RTL.
3. Explain what your signals are doing to someone else.
4. Move on once the idea actually makes sense.

You're done with a checkpoint when you can explain what gets stored, what changes on the clock edge, and when the output is valid.

## Checkpoint 1: Pixel Struct And Package

### Goal

First, understand what a pixel even is in this project.

A pixel isn't just one number. It's three numbers bundled together:

```text
red
green
blue
```

Each channel is 8 bits, so one pixel is really three 8-bit values grouped into one `pixel_t`.

### What To Do

Open `src/pixel_pkg.sv` and find `pixel_t`.

Answer these:

1. How many bits is each color channel?
2. How many total bits are in one pixel?
3. Why do we put `pixel_t` in a package instead of copying it into every file?

### Quick Practice

Given these four pixels:

```text
pixel_0 = R:100 G:26  B:120
pixel_1 = R:40  G:30  B:120
pixel_2 = R:100 G:200 B:21
pixel_3 = R:100 G:130 B:20
```

Write the red values, green values, and blue values as three separate lists.

### Done When

You can explain that we don't take the median of the whole pixel at once. We take the median of red, green, and blue separately, then put the output pixel back together.

## Checkpoint 2: Median Of Four Values

### Goal

Build the smallest useful piece: a function that takes four 8-bit numbers and returns the median.

Because this project uses a 2x2 kernel, we always have four values. Since four is even, there's no single middle value. So we sort the four values, take the two middle values, average them, and round up if needed.

Example:

```text
values: 26, 30, 200, 130
sorted: 26, 30, 130, 200
middle values: 30 and 130
median: (30 + 130) / 2 = 80
```

If the average ends in `.5`, round up.

Example:

```text
values: 20, 21, 120, 120
middle values: 21 and 120
average: 70.5
rounded result: 71
```

### What To Do

Implement or look at a helper function like this:

```systemverilog
function automatic logic [PIXEL_W-1:0] find_median_channel(
  input logic [PIXEL_W-1:0] value_0_i,
  input logic [PIXEL_W-1:0] value_1_i,
  input logic [PIXEL_W-1:0] value_2_i,
  input logic [PIXEL_W-1:0] value_3_i
);
```

The function should:

1. Copy the four inputs into temporary variables.
2. Sort the four values from smallest to largest.
3. Add the two middle values.
4. Add `1` before dividing by `2` so `.5` rounds up.
5. Return the final 8-bit median value.

### Done When

You can calculate the median of four values by hand and explain why the sum needs one extra bit.

## Checkpoint 3: RGB Median

### Goal

Now use the median helper three times:

```text
once for red
once for green
once for blue
```

### What To Do

Given these four pixels:

```text
top_left     = R:100 G:26  B:120
top_right    = R:40  G:30  B:120
bottom_left  = R:100 G:200 B:21
bottom_right = R:100 G:130 B:20
```

Compute:

```text
red median   = ?
green median = ?
blue median  = ?
output pixel = R:? G:? B:?
```

### RTL Task

Write or look at a small module that takes a 2x2 group of pixels and outputs one median pixel.

This module shouldn't care about the full image, counters, rows, columns, or line buffers. Its only job is:

```text
four pixels in -> one median pixel out
```

### Done When

You can explain why this part is combinational logic. If the four input pixels change, the output changes without waiting for a clock edge.

## Checkpoint 4: Row And Column Counter

### Goal

Track where the incoming pixel is in the image.

Pixels come in left to right, then top to bottom:

```text
(0,0), (1,0), (2,0), (3,0)
(0,1), (1,1), (2,1), (3,1)
(0,2), (1,2), (2,2), (3,2)
(0,3), (1,3), (2,3), (3,3)
```

### What To Do

For a 4x4 image, write down the next value of `col_count_q` and `row_count_q` after each valid input pixel.

### RTL Task

Build the counter logic with these rules:

1. On reset, row and column go to 0.
2. On `start_i`, row and column go to 0.
3. If `pixel_valid_i` is 0, the counters don't move.
4. If `pixel_valid_i` is 1 and we're not at the last column, move one column to the right.
5. If `pixel_valid_i` is 1 and we are at the last column, go back to column 0 and move down one row.

### Done When

You can explain why the counters only move when `pixel_valid_i` is high.

## Checkpoint 5: When Is A 2x2 Window Valid?

### Goal

Figure out when we actually have enough pixels to make a 2x2 window.

A 2x2 window ending at the current pixel looks like this:

```text
top-left      top-right
bottom-left   current pixel
```

So the current pixel needs:

1. A row above it.
2. A column to the left of it.

That means the first row doesn't work, and the first column doesn't work.

### What To Do

For a 4x4 input image, mark each coordinate as valid or invalid:

```text
(0,0) invalid   (1,0) invalid   (2,0) invalid   (3,0) invalid
(0,1) invalid   (1,1) valid     (2,1) valid     (3,1) valid
(0,2) invalid   (1,2) valid     (2,2) valid     (3,2) valid
(0,3) invalid   (1,3) valid     (2,3) valid     (3,3) valid
```

### RTL Task

Make a signal like this:

```systemverilog
assign window_valid = pixel_valid_i &&
                      (row_count_q != '0) &&
                      (col_count_q != '0);
```

### Done When

You can explain why a 4x4 input image makes a 3x3 output image.

## Checkpoint 6: The Line Buffer

### Goal

Understand why we need memory.

The module only gets one new pixel at a time. But a 2x2 window needs four pixels. So the design has to remember pixels from earlier cycles.

### What To Do

Label these four pixels:

```text
top-left      top-right
bottom-left   bottom-right
```

Then match them to the hardware:

```text
bottom-right = current input pixel
bottom-left  = previous pixel from the current row
top-right    = pixel from the same column in the previous row
top-left     = pixel from the previous column in the previous row
```

### RTL Task

You'll probably use signals like:

```systemverilog
pixel_t line_buffer_q [IMAGE_LEN];
pixel_t current_row_prev_pixel_q;
pixel_t previous_row_prev_pixel_q;
```

The line buffer stores the previous row. Every time a valid pixel comes in, the current input pixel replaces the old pixel at that column.

### Done When

You can explain why `top_right` has to be read from the line buffer before the current pixel overwrites that spot.

## Checkpoint 7: Output Valid Timing

### Goal

Make sure `pixel_valid_o` lines up with the output pixel.

### What To Do

Answer these:

1. Should `pixel_valid_o` be high for the first input pixel? Why?
2. Should `pixel_valid_o` be high at coordinate `(1,1)`? Why?
3. What should happen if `pixel_valid_i` is low for one cycle?

### RTL Task

Register the output pixel and the valid signal together.

The rule is simple:

```text
If pixel_o updates this cycle, pixel_valid_o should describe that same pixel_o.
```

### Done When

You can explain which output pixel is valid on each cycle.

## Checkpoint 8: Done Signal

### Goal

Pulse `done_o` after the final valid output pixel.

### What To Do

For a 4x4 image:

1. What's the last input coordinate?
2. Is that coordinate also a valid 2x2 window?
3. How many output pixels should we get total?

### RTL Task

Make a signal for the final valid window:

```systemverilog
assign final_window = window_valid &&
                      (row_count_q == LAST_ROW) &&
                      (col_count_q == LAST_COL);
```

Then make `done_o` pulse when that final output pixel comes out.

### Done When

You can explain why `done_o` should pulse once instead of staying high forever.

## Checkpoint 9: Put The Whole Thing Together

### Goal

Now connect all the pieces:

1. Pixel package
2. Median helper function
3. 2x2 RGB median calculation
4. Row and column counters
5. Line buffer
6. Window valid signal
7. Output pixel register
8. Done signal

### What To Do

Before writing the full module, draw the datapath:

```text
pixel_i
  |
  +--> current row previous pixel
  |
  +--> line buffer
  |
  +--> 2x2 window --> median calculation --> pixel_o
```

Then write the RTL in chunks. Don't try to write the entire thing in one shot.

### Done When

The design compiles, and you can explain every signal that stores state.

## Checkpoint 10: Run The Provided Test

### Goal

Run the provided test so you can see if your RTL output matches the expected output for the starter example.

### What To Do

From the `sim` folder, run the provided command or Makefile target.

The provided test will:

1. Read input pixels from a CSV file.
2. Feed them into the RTL one pixel at a time.
3. Compare your RTL output against the expected CSV file.
4. Print pass or fail.

### Done When

The simulation prints:

```text
PASS: median filter output matched expected CSV.
```

That means your RTL matches the expected CSV for the starter example. It doesn't mean you wrote a full verification environment, covered every corner case, or tested it on hardware.

## Questions Leads Can Ask

Use these to check if someone actually understands the project:

1. Which signals are combinational, and which ones are sequential?
2. What does the line buffer store?
3. Why is the first valid output at row 1, column 1?
4. What happens when `pixel_valid_i` is low?
5. Why does the 2x2 median need rounding?
6. Why does a 4x4 input image produce a 3x3 output image?
7. When should `pixel_valid_o` go high?
8. When should `done_o` go high?
9. What does the provided PASS message actually prove?
10. What does the provided PASS message not prove?


