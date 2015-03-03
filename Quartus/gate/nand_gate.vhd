Library ieee;
Use ieee.std_logic_1164.all;
Entity nand_gate is
Port(a_nand,b_nand:in std_logic;
     c_nand:out std_logic
     );
End nand_gate;
Architecture behave of nand_gate is
Begin
c_nand<=a_nand nand b_nand;
End behave;