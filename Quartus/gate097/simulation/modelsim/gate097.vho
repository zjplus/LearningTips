-- Copyright (C) 1991-2014 Altera Corporation. All rights reserved.
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, the Altera Quartus II License Agreement,
-- the Altera MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Altera and sold by Altera or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 14.0.0 Build 200 06/17/2014 SJ Web Edition"

-- DATE "12/13/2014 19:33:29"

-- 
-- Device: Altera EP4CGX15BF14C6 Package FBGA169
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIV;
LIBRARY IEEE;
USE CYCLONEIV.CYCLONEIV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	gate097 IS
    PORT (
	a : IN std_logic;
	b : IN std_logic;
	c_and : OUT std_logic;
	d_or : OUT std_logic;
	e_nand : OUT std_logic;
	f_nor : OUT std_logic;
	g_xor : OUT std_logic
	);
END gate097;

-- Design Ports Information
-- c_and	=>  Location: PIN_N8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d_or	=>  Location: PIN_B11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- e_nand	=>  Location: PIN_L5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f_nor	=>  Location: PIN_A12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- g_xor	=>  Location: PIN_K11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a	=>  Location: PIN_L4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b	=>  Location: PIN_L9,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF gate097 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_a : std_logic;
SIGNAL ww_b : std_logic;
SIGNAL ww_c_and : std_logic;
SIGNAL ww_d_or : std_logic;
SIGNAL ww_e_nand : std_logic;
SIGNAL ww_f_nor : std_logic;
SIGNAL ww_g_xor : std_logic;
SIGNAL \c_and~output_o\ : std_logic;
SIGNAL \d_or~output_o\ : std_logic;
SIGNAL \e_nand~output_o\ : std_logic;
SIGNAL \f_nor~output_o\ : std_logic;
SIGNAL \g_xor~output_o\ : std_logic;
SIGNAL \a~input_o\ : std_logic;
SIGNAL \b~input_o\ : std_logic;
SIGNAL \c_and~0_combout\ : std_logic;
SIGNAL \d_or~0_combout\ : std_logic;
SIGNAL \g_xor~0_combout\ : std_logic;
SIGNAL \ALT_INV_d_or~0_combout\ : std_logic;
SIGNAL \ALT_INV_c_and~0_combout\ : std_logic;

BEGIN

ww_a <= a;
ww_b <= b;
c_and <= ww_c_and;
d_or <= ww_d_or;
e_nand <= ww_e_nand;
f_nor <= ww_f_nor;
g_xor <= ww_g_xor;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_d_or~0_combout\ <= NOT \d_or~0_combout\;
\ALT_INV_c_and~0_combout\ <= NOT \c_and~0_combout\;

-- Location: IOOBUF_X20_Y0_N9
\c_and~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \c_and~0_combout\,
	devoe => ww_devoe,
	o => \c_and~output_o\);

-- Location: IOOBUF_X24_Y31_N2
\d_or~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \d_or~0_combout\,
	devoe => ww_devoe,
	o => \d_or~output_o\);

-- Location: IOOBUF_X14_Y0_N9
\e_nand~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_c_and~0_combout\,
	devoe => ww_devoe,
	o => \e_nand~output_o\);

-- Location: IOOBUF_X20_Y31_N9
\f_nor~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_d_or~0_combout\,
	devoe => ww_devoe,
	o => \f_nor~output_o\);

-- Location: IOOBUF_X33_Y11_N2
\g_xor~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \g_xor~0_combout\,
	devoe => ww_devoe,
	o => \g_xor~output_o\);

-- Location: IOIBUF_X8_Y0_N8
\a~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a,
	o => \a~input_o\);

-- Location: IOIBUF_X24_Y0_N8
\b~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b,
	o => \b~input_o\);

-- Location: LCCOMB_X22_Y5_N16
\c_and~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \c_and~0_combout\ = (\a~input_o\ & \b~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a~input_o\,
	datad => \b~input_o\,
	combout => \c_and~0_combout\);

-- Location: LCCOMB_X22_Y5_N18
\d_or~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \d_or~0_combout\ = (\a~input_o\) # (\b~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a~input_o\,
	datad => \b~input_o\,
	combout => \d_or~0_combout\);

-- Location: LCCOMB_X22_Y5_N20
\g_xor~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \g_xor~0_combout\ = \a~input_o\ $ (\b~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a~input_o\,
	datad => \b~input_o\,
	combout => \g_xor~0_combout\);

ww_c_and <= \c_and~output_o\;

ww_d_or <= \d_or~output_o\;

ww_e_nand <= \e_nand~output_o\;

ww_f_nor <= \f_nor~output_o\;

ww_g_xor <= \g_xor~output_o\;
END structure;


