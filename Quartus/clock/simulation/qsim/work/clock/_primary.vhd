library verilog;
use verilog.vl_types.all;
entity clock is
    port(
        clk             : in     vl_logic;
        sout            : out    vl_logic_vector(5 downto 0);
        mout            : out    vl_logic_vector(5 downto 0);
        hout            : out    vl_logic_vector(4 downto 0)
    );
end clock;
