import pixel_pkg::*;

module median_kernel_calc (
    input  pixel_t kernel_i[KERNEL_LEN][KERNEL_LEN],
    output pixel_t pixel_o
);

  // TODO: Write a combinational block that calls the find_median_channel function on each color
  // Pass in all kernel values => [0][0], [0][1], [1][0], [1][1]
  // Re-combine the three function calls into one output pixel (pixel_o)

endmodule
