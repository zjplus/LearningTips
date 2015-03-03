library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
entity FrequencyDivision097 is
port (clk:in std_logic;
				  Q1:inout std_logic;
				  Q2:out std_logic);
end FrequencyDivision097;
architecture behav of FrequencyDivision097 is
begin
	process(clk)
		variable QI:std_logic_vector(3 downto 0);
		variable QX:std_logic_vector(3 downto 0);
	begin 
		--六分频
		if clk'event and clk='1' then
				if QI<6 then QI:=QI+1;
				else QI:=(others=>'0');
				end if;
			end if;
		if QI=6 then Q1<='1';
		else Q1<='0';
		end if;
		--
		if Q1'event and Q1='1' then
			if QX<2 then QX:=QX+1;
			else QX:=(others=>'0');
			end if;
		end if;
		if QX=2 then Q2<='1';
		else Q2<='0';
		end if;
	end process;
end behav;