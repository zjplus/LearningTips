library verilog;
use verilog.vl_types.all;
entity counter is
    port(
        clk             : in     vl_logic;
        reset           : in     vl_logic;
        set             : in     vl_logic;
        Q               : out    vl_logic_vector(3 downto 0);
        C               : out    vl_logic
    );
end counter;
