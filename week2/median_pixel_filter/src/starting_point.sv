import pixel_pkg::*;

module median_filter_v2 #(
  parameter int IMAGE_LEN    = 1080,
  parameter int IMAGE_HEIGHT = 720
) (
  input logic clk,
  input logic rst, //synchronous reset high
  input logic start_i, //starting a new frame
  input logic pixel_valid_i, //current input pixel is valid
  input       pixel_t pixel_i, //input pixel data

  output logic done_o, //the whole image is filtered
  output logic pixel_valid_o, //current output pixel is valid
  output       pixel_t pixel_o //output pixel data
);

  //NOTE: Remember, _q means the signal is clocked, _d means the signal is combinational

  // Local parameters
  localparam int X_COUNTER_W = $clog2(IMAGE_LEN);
  localparam int Y_COUNTER_W = $clog2(IMAGE_HEIGHT);
  localparam int SHIFT_REG_W = IMAGE_LEN + KERNEL_LEN - 1;


  // FSM States
  // TODO: Below this enum, declare two instances of 'state_t',
  // One should represent the current state, then next represents the next state
  typedef enum logic [1:0] {IDLE, CALCULATE} state_t;


  // Row/Col Counters
  // TODO: Use the local parameters above to create an x_counter and a y_counter
  // Each counter needs an _q signal to store the counter value, and an _d signal to update that value


  // Storage Buffer to hold pixels
  pixel_t                 pixel_shift_reg_d[SHIFT_REG_W];
  pixel_t                 pixel_shift_reg_q[SHIFT_REG_W];
  pixel_t                 kernel           [KERNEL_LEN] [KERNEL_LEN];
  pixel_t                 pixel_d;

  // Control Signals
  logic x_inbounds;
  logic y_inbounds;
  logic kernel_valid;

  logic done_d;

  // TODO: Write a combinational process to check if things are inbounds based on the current X and Y count
  // If the x counter is inbounds, set x_inbounds = 1, if y counter is inbounds, set y_inbounds = 1, else 0

  // TODO: write a combinational process that shifts the input pixel into pixel_shift_reg_d
  // Make sure to check that the input pixel is valid.
  
  // Compute next State
  always_comb begin
    // TODO: Place your default values here to avoid latches


    // TODO Write a case statement here to decode the next state logic
    // This is the 1st process in your two process FSM
  end

  // This masks the kernel to make things easier to read 
  always_comb begin
    kernel[0][0] = pixel_shift_reg_q[SHIFT_REG_W-1];
    kernel[0][1] = pixel_shift_reg_q[SHIFT_REG_W-2];
    kernel[1][0] = pixel_shift_reg_q[0];
    kernel[1][1] = pixel_i;
  end

  // TODO: Instatitate an instance of the 'median_kernel_calc' module
  // This look in the folder for to see median_kernel_calc's input and output ports
  // HINT: Pass the entire kernel as the input into the module

  // TODO: Write a synchronous clocked block to update our registers
  // Make sure that this block has a synchronous, active high reset

endmodule
