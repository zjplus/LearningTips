Library ieee;
Use ieee.std_logic_1164.all;
Entity and_gate097 is
Port(a_and,b_and:in std_logic;
     c_and:out std_logic
     );
End and_gate097;
Architecture behave of and_gate097 is
Begin
c_and<=a_and and b_and;
End behave;