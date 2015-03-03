library verilog;
use verilog.vl_types.all;
entity Clock_097_vlg_check_tst is
    port(
        hout            : in     vl_logic_vector(4 downto 0);
        mout            : in     vl_logic_vector(5 downto 0);
        sout            : in     vl_logic_vector(5 downto 0);
        sampler_rx      : in     vl_logic
    );
end Clock_097_vlg_check_tst;
