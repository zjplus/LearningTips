Library ieee;
Use ieee.std_logic_1164.all;
Entity nand_gate097 is
Port(a_nand,b_nand:in std_logic;
     c_nand:out std_logic
     );
End nand_gate097;
Architecture behave of nand_gate097 is
Begin
c_nand<=a_nand nand b_nand;
End behave;