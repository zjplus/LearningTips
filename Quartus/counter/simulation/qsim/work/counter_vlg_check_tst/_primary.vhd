library verilog;
use verilog.vl_types.all;
entity counter_vlg_check_tst is
    port(
        C               : in     vl_logic;
        Q               : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end counter_vlg_check_tst;
