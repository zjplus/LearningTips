Library ieee;
Use ieee.std_logic_1164.all;
Entity or_gate097 is
Port(a_or,b_or:in std_logic;c_or:out std_logic);
End or_gate097;
Architecture behave of or_gate097 is
Begin
c_or<=a_or or b_or;
End behave;