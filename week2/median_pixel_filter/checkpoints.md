# Median Pixel Filter Checkpoints

This file breaks the median pixel filter project into smaller checkpoints. Students should complete these in order before trying to write the full `median_filter` module.

The goal is not to memorize SystemVerilog syntax. The goal is to understand how pixels move through hardware one clock cycle at a time.

## How To Use These Checkpoints

For each checkpoint:

1. Read the goal.
2. Fill in only the missing RTL for that checkpoint.
3. Explain the signal timing to a teammate or lead.
4. Move on only when the behavior makes sense.

A checkpoint is done when the student can explain what the circuit stores, what changes on a clock edge, and when the output is valid.

## Checkpoint 1: Pixel Struct And Package

### Goal

Understand that one pixel is not one number. It is a bundle of three color channels: red, green, and blue.

### Student Task

Open `src/pixel_pkg.sv` and find `pixel_t`.

Answer these questions:

1. How many bits wide is each color channel?
2. How many total bits are in one `pixel_t`?
3. Why do we put `pixel_t` in a package instead of redefining it in every file?

### Mini RTL Task

Create four example pixels on paper:

```text
pixel_0 = R:100 G:26  B:120
pixel_1 = R:40  G:30  B:120
pixel_2 = R:100 G:200 B:21
pixel_3 = R:100 G:130 B:20
```

Then write down the red list, green list, and blue list separately.

### Done When

The student can explain that the median filter processes each color channel separately, then recombines the result into one output pixel.

## Checkpoint 2: Median Of Four Values

### Goal

Build the smallest useful part of the project: a function that takes four 8-bit numbers and returns their median.

For a 2x2 kernel, there are four values. Since four is even, there is no single middle value. The median is the average of the two middle values after sorting.

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

### Student Task

Implement or inspect a helper function like this:

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

The student can compute the median of four values by hand and explain why the sum needs one extra bit.

## Checkpoint 3: RGB Median

### Goal

Use the median helper three times: once for red, once for green, and once for blue.

### Student Task

Given four pixels:

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

Write or inspect a module that takes a 2x2 group of pixels and produces one median pixel.

The module should not care about image width, image height, counters, or line buffers. It should only know how to calculate the median of four pixels.

### Done When

The student can explain why this is combinational logic: if the four input pixels change, the output median pixel changes without waiting for a clock edge.

## Checkpoint 4: Row And Column Counter

### Goal

Track where the incoming pixel is in the image.

Pixels arrive left to right, top to bottom:

```text
(0,0), (1,0), (2,0), (3,0)
(0,1), (1,1), (2,1), (3,1)
(0,2), (1,2), (2,2), (3,2)
(0,3), (1,3), (2,3), (3,3)
```

### Student Task

For a 4x4 image, fill in the next value of `col_count_q` and `row_count_q` after each valid input pixel.

### RTL Task

Implement counter logic with these rules:

1. On reset, row and column go to 0.
2. On `start_i`, row and column go to 0.
3. If `pixel_valid_i` is 0, the counters hold their value.
4. If `pixel_valid_i` is 1 and the current column is not the last column, increment column.
5. If `pixel_valid_i` is 1 and the current column is the last column, set column to 0 and increment row.

### Done When

The student can explain why counters should only move when `pixel_valid_i` is high.

## Checkpoint 5: When Is A 2x2 Window Valid?

### Goal

Understand that the filter cannot produce an output for the first row or first column.

A 2x2 window ending at the current pixel needs:

```text
top-left      top-right
bottom-left   current pixel
```

That means the current pixel must have:

1. A row above it.
2. A column to the left of it.

### Student Task

For a 4x4 input image, mark each input coordinate as valid or invalid:

```text
(0,0) invalid   (1,0) invalid   (2,0) invalid   (3,0) invalid
(0,1) invalid   (1,1) valid     (2,1) valid     (3,1) valid
(0,2) invalid   (1,2) valid     (2,2) valid     (3,2) valid
(0,3) invalid   (1,3) valid     (2,3) valid     (3,3) valid
```

### RTL Task

Create a signal like:

```systemverilog
assign window_valid = pixel_valid_i &&
                      (row_count_q != '0) &&
                      (col_count_q != '0);
```

### Done When

The student can explain why a 4x4 input image creates a 3x3 output image.

## Checkpoint 6: The Line Buffer

### Goal

Understand why the design needs memory.

When the current pixel arrives, the module only sees one new pixel. To build a 2x2 window, it must remember old pixels from earlier cycles.

### Student Task

Label these four pixels:

```text
top-left      top-right
bottom-left   bottom-right
```

Then match them to hardware storage:

```text
bottom-right = current input pixel
bottom-left  = previous pixel from the current row
top-right    = pixel from the same column in the previous row
top-left     = pixel from the previous column in the previous row
```

### RTL Task

Use:

```systemverilog
pixel_t line_buffer_q [IMAGE_LEN];
pixel_t current_row_prev_pixel_q;
pixel_t previous_row_prev_pixel_q;
```

The line buffer stores the previous row. Each time a valid pixel arrives, the current input pixel replaces the old pixel at that column.

### Done When

The student can explain why `top_right` must be read from the line buffer before the current pixel overwrites that location.

## Checkpoint 7: Output Valid Timing

### Goal

Connect `pixel_valid_o` to the moment when the output pixel is real.

### Student Task

Answer these questions:

1. Should `pixel_valid_o` be high for the first input pixel? Why or why not?
2. Should `pixel_valid_o` be high at coordinate `(1,1)`? Why?
3. What should happen if `pixel_valid_i` is low for one cycle?

### RTL Task

Register the output pixel and valid signal together.

The important rule is:

```text
If pixel_o updates this clock cycle, pixel_valid_o should describe that same output pixel.
```

### Done When

The student can explain what output is valid on a waveform or in a cycle table.

## Checkpoint 8: Done Signal

### Goal

Raise `done_o` after the final valid output pixel of the image.

### Student Task

For a 4x4 image:

1. What is the last input coordinate?
2. Is that input coordinate also a valid 2x2 window?
3. How many total output pixels should be produced?

### RTL Task

Create a signal for the final valid window:

```systemverilog
assign final_window = window_valid &&
                      (row_count_q == LAST_ROW) &&
                      (col_count_q == LAST_COL);
```

Then make `done_o` pulse when the final output pixel is produced.

### Done When

The student can explain why `done_o` should pulse once, not stay high forever.

## Checkpoint 9: Full Integration

### Goal

Connect all project pieces:

1. Pixel package
2. Median helper function
3. 2x2 RGB median calculation
4. Row and column counters
5. Line buffer
6. Window valid signal
7. Output pixel register
8. Done signal

### Student Task

Before writing code, draw the datapath:

```text
pixel_i
  |
  +--> current row previous pixel
  |
  +--> line buffer
  |
  +--> 2x2 window --> median calculation --> pixel_o
```

Then write the RTL in small sections instead of all at once.

### Done When

The design compiles and the student can explain every state-holding signal in the module.

## Checkpoint 10: Run The Provided Test

### Goal

Use the provided simulation to check the completed RTL.

### Student Task

From the `sim` folder, run the provided simulation command or Makefile target.

The testbench will:

1. Read input pixels from a CSV file.
2. Feed them into the RTL one pixel at a time.
3. Compare the RTL output pixels against the expected CSV file.
4. Print pass or fail.

### Done When

The simulation prints:

```text
PASS: median filter output matched expected CSV.
```

This means the RTL passed the provided test. It does not mean the design has been exhaustively verified or tested on hardware.

## Lead Review Questions

Use these when checking student understanding:

1. Which signals are combinational and which signals are sequential?
2. What does the line buffer store?
3. Why is the first valid output at row 1, column 1?
4. What happens when `pixel_valid_i` is low?
5. Why does the 2x2 median need rounding?
6. Why does a 4x4 input image produce a 3x3 output image?
7. What exact cycle should `pixel_valid_o` go high?
8. What exact cycle should `done_o` go high?
9. What does the provided test prove?
10. What does the provided test not prove?
