library verilog;
use verilog.vl_types.all;
entity counter_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        reset           : in     vl_logic;
        set             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end counter_vlg_sample_tst;
