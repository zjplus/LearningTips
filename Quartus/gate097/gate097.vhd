Library ieee;
Use ieee.std_logic_1164.all;
Entity gate097 is
Port(a,b,c,d:in std_logic;e:out std_logic);
End gate097;
Architecture behave of gate097 is
component and_gate097  --调用与门
	Port(a_and,b_and:in std_logic;c_and:out std_logic);
end component;
component or_gate097  --调用或门
	Port(a_or,b_or:in std_logic;c_or:out std_logic);
end component;
component nand_gate097
	Port(a_nand,b_nand:in std_logic;c_nand:out std_logic);
end component;
signal s1,s2 : std_logic;
Begin
u1 : and_gate097 port map(a_and=>a,b_and=>b,c_and=>s1);
u2 : or_gate097 port map(a_or=>c,b_or=>d,c_or=>s2);
u3 : nand_gate097 port map(a_nand=>s1,b_nand=>s2,c_nand=>e);
End behave;