library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
entity counter is
port (clk,reset,set:in std_logic;
				  Q:out std_logic_vector(3 downto 0);
				  C:out std_logic);
end counter;
architecture behav of counter is
begin
	process(clk,reset,set)
		variable QI:std_logic_vector(3 downto 0);
	begin 
		if reset='1' then QI:=(others=>'0');
		elsif clk'event and clk='1' then
			if set='1' then
				if QI<15 then QI:=QI+1;
				else QI:=(others=>'0');
				end if;
			end if;
		end if;
		if QI=15 then C<='1';
		else C<='0';
		end if;
		Q<=QI;
	end process;
end behav;