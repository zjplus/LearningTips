library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity clock is
port (clk:in std_logic;
		sout:out std_logic_vector(5 downto 0);
      mout:out std_logic_vector(5 downto 0);
		hout:out std_logic_vector(4 downto 0)
);
end clock;

architecture clock_body of clock is
signal sc:std_logic; --秒进位信号
signal mc:std_logic; --分进位信号
begin
process(clk)
variable s:std_logic_vector(5 downto 0);
variable m:std_logic_vector(5 downto 0);
variable h:std_logic_vector(4 downto 0);
begin
--秒进位
if clk'event and clk='1'then
	if s=59 then 
		s:=(others=>'0');
		sc<='1';
	else
		s:=s+1;
		sc<='0';
	end if;
end if;

--分进位
if sc'event and sc='1'then
	if m=59 then 
		m:=(others=>'0');
		mc<='1';
	else
		m:=m+1;
		mc<='0';
	end if;
end if;

--时进位
if mc'event and mc='1'then
	if h=23 then 
		h:=(others=>'0');
	else
		h:=h+1;
	end if;
end if;

--为输出端口赋值
sout<=s;
mout<=m;
hout<=h;
end process;
end clock_body;