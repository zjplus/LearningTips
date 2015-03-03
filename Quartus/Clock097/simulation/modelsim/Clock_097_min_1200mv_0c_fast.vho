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

-- DATE "12/27/2014 21:22:58"

-- 
-- Device: Altera EP4CGX15BF14C6 Package FBGA169
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIV;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIV.CYCLONEIV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	Clock_097 IS
    PORT (
	clk : IN std_logic;
	sout : OUT std_logic_vector(5 DOWNTO 0);
	mout : OUT std_logic_vector(5 DOWNTO 0);
	hout : OUT std_logic_vector(4 DOWNTO 0)
	);
END Clock_097;

-- Design Ports Information
-- sout[0]	=>  Location: PIN_N8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sout[1]	=>  Location: PIN_N4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sout[2]	=>  Location: PIN_N6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sout[3]	=>  Location: PIN_L7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sout[4]	=>  Location: PIN_L5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sout[5]	=>  Location: PIN_M6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- mout[0]	=>  Location: PIN_A8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- mout[1]	=>  Location: PIN_A11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- mout[2]	=>  Location: PIN_A6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- mout[3]	=>  Location: PIN_C6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- mout[4]	=>  Location: PIN_A7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- mout[5]	=>  Location: PIN_B6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- hout[0]	=>  Location: PIN_B11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- hout[1]	=>  Location: PIN_C8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- hout[2]	=>  Location: PIN_A13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- hout[3]	=>  Location: PIN_B10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- hout[4]	=>  Location: PIN_B13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_J7,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Clock_097 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_clk : std_logic;
SIGNAL ww_sout : std_logic_vector(5 DOWNTO 0);
SIGNAL ww_mout : std_logic_vector(5 DOWNTO 0);
SIGNAL ww_hout : std_logic_vector(4 DOWNTO 0);
SIGNAL \clk~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \sc~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \mc~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \sout[0]~output_o\ : std_logic;
SIGNAL \sout[1]~output_o\ : std_logic;
SIGNAL \sout[2]~output_o\ : std_logic;
SIGNAL \sout[3]~output_o\ : std_logic;
SIGNAL \sout[4]~output_o\ : std_logic;
SIGNAL \sout[5]~output_o\ : std_logic;
SIGNAL \mout[0]~output_o\ : std_logic;
SIGNAL \mout[1]~output_o\ : std_logic;
SIGNAL \mout[2]~output_o\ : std_logic;
SIGNAL \mout[3]~output_o\ : std_logic;
SIGNAL \mout[4]~output_o\ : std_logic;
SIGNAL \mout[5]~output_o\ : std_logic;
SIGNAL \hout[0]~output_o\ : std_logic;
SIGNAL \hout[1]~output_o\ : std_logic;
SIGNAL \hout[2]~output_o\ : std_logic;
SIGNAL \hout[3]~output_o\ : std_logic;
SIGNAL \hout[4]~output_o\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \clk~inputclkctrl_outclk\ : std_logic;
SIGNAL \Add0~0_combout\ : std_logic;
SIGNAL \Add0~1\ : std_logic;
SIGNAL \Add0~2_combout\ : std_logic;
SIGNAL \Add0~3\ : std_logic;
SIGNAL \Add0~5\ : std_logic;
SIGNAL \Add0~6_combout\ : std_logic;
SIGNAL \s~1_combout\ : std_logic;
SIGNAL \Equal0~0_combout\ : std_logic;
SIGNAL \Add0~7\ : std_logic;
SIGNAL \Add0~9\ : std_logic;
SIGNAL \Add0~10_combout\ : std_logic;
SIGNAL \s~3_combout\ : std_logic;
SIGNAL \Add0~8_combout\ : std_logic;
SIGNAL \s~2_combout\ : std_logic;
SIGNAL \Add0~4_combout\ : std_logic;
SIGNAL \s~0_combout\ : std_logic;
SIGNAL \Equal0~1_combout\ : std_logic;
SIGNAL \sc~q\ : std_logic;
SIGNAL \sc~clkctrl_outclk\ : std_logic;
SIGNAL \Add1~0_combout\ : std_logic;
SIGNAL \Add1~1\ : std_logic;
SIGNAL \Add1~2_combout\ : std_logic;
SIGNAL \Add1~3\ : std_logic;
SIGNAL \Add1~4_combout\ : std_logic;
SIGNAL \Add1~5\ : std_logic;
SIGNAL \Add1~6_combout\ : std_logic;
SIGNAL \m~1_combout\ : std_logic;
SIGNAL \Add1~7\ : std_logic;
SIGNAL \Add1~8_combout\ : std_logic;
SIGNAL \m~2_combout\ : std_logic;
SIGNAL \Add1~9\ : std_logic;
SIGNAL \Add1~10_combout\ : std_logic;
SIGNAL \m~3_combout\ : std_logic;
SIGNAL \Equal1~0_combout\ : std_logic;
SIGNAL \m~0_combout\ : std_logic;
SIGNAL \Equal1~1_combout\ : std_logic;
SIGNAL \mc~q\ : std_logic;
SIGNAL \mc~clkctrl_outclk\ : std_logic;
SIGNAL \Add2~0_combout\ : std_logic;
SIGNAL \Add2~1\ : std_logic;
SIGNAL \Add2~2_combout\ : std_logic;
SIGNAL \Add2~3\ : std_logic;
SIGNAL \Add2~4_combout\ : std_logic;
SIGNAL \Add2~5\ : std_logic;
SIGNAL \Add2~7\ : std_logic;
SIGNAL \Add2~8_combout\ : std_logic;
SIGNAL \h~1_combout\ : std_logic;
SIGNAL \Equal2~0_combout\ : std_logic;
SIGNAL \Add2~6_combout\ : std_logic;
SIGNAL \h~0_combout\ : std_logic;
SIGNAL s : std_logic_vector(5 DOWNTO 0);
SIGNAL m : std_logic_vector(5 DOWNTO 0);
SIGNAL h : std_logic_vector(4 DOWNTO 0);

BEGIN

ww_clk <= clk;
sout <= ww_sout;
mout <= ww_mout;
hout <= ww_hout;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\clk~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \clk~input_o\);

\sc~clkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \sc~q\);

\mc~clkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \mc~q\);

-- Location: IOOBUF_X20_Y0_N9
\sout[0]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => s(0),
	devoe => ww_devoe,
	o => \sout[0]~output_o\);

-- Location: IOOBUF_X10_Y0_N9
\sout[1]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => s(1),
	devoe => ww_devoe,
	o => \sout[1]~output_o\);

-- Location: IOOBUF_X12_Y0_N2
\sout[2]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => s(2),
	devoe => ww_devoe,
	o => \sout[2]~output_o\);

-- Location: IOOBUF_X14_Y0_N2
\sout[3]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => s(3),
	devoe => ww_devoe,
	o => \sout[3]~output_o\);

-- Location: IOOBUF_X14_Y0_N9
\sout[4]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => s(4),
	devoe => ww_devoe,
	o => \sout[4]~output_o\);

-- Location: IOOBUF_X12_Y0_N9
\sout[5]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => s(5),
	devoe => ww_devoe,
	o => \sout[5]~output_o\);

-- Location: IOOBUF_X12_Y31_N9
\mout[0]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => m(0),
	devoe => ww_devoe,
	o => \mout[0]~output_o\);

-- Location: IOOBUF_X20_Y31_N2
\mout[1]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => m(1),
	devoe => ww_devoe,
	o => \mout[1]~output_o\);

-- Location: IOOBUF_X10_Y31_N2
\mout[2]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => m(2),
	devoe => ww_devoe,
	o => \mout[2]~output_o\);

-- Location: IOOBUF_X14_Y31_N2
\mout[3]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => m(3),
	devoe => ww_devoe,
	o => \mout[3]~output_o\);

-- Location: IOOBUF_X12_Y31_N2
\mout[4]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => m(4),
	devoe => ww_devoe,
	o => \mout[4]~output_o\);

-- Location: IOOBUF_X14_Y31_N9
\mout[5]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => m(5),
	devoe => ww_devoe,
	o => \mout[5]~output_o\);

-- Location: IOOBUF_X24_Y31_N2
\hout[0]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => h(0),
	devoe => ww_devoe,
	o => \hout[0]~output_o\);

-- Location: IOOBUF_X22_Y31_N9
\hout[1]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => h(1),
	devoe => ww_devoe,
	o => \hout[1]~output_o\);

-- Location: IOOBUF_X26_Y31_N2
\hout[2]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => h(2),
	devoe => ww_devoe,
	o => \hout[2]~output_o\);

-- Location: IOOBUF_X24_Y31_N9
\hout[3]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => h(3),
	devoe => ww_devoe,
	o => \hout[3]~output_o\);

-- Location: IOOBUF_X26_Y31_N9
\hout[4]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => h(4),
	devoe => ww_devoe,
	o => \hout[4]~output_o\);

-- Location: IOIBUF_X16_Y0_N15
\clk~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: CLKCTRL_G17
\clk~inputclkctrl\ : cycloneiv_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \clk~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \clk~inputclkctrl_outclk\);

-- Location: LCCOMB_X15_Y1_N14
\Add0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add0~0_combout\ = s(0) $ (VCC)
-- \Add0~1\ = CARRY(s(0))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => s(0),
	datad => VCC,
	combout => \Add0~0_combout\,
	cout => \Add0~1\);

-- Location: FF_X15_Y1_N15
\s[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \Add0~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => s(0));

-- Location: LCCOMB_X15_Y1_N16
\Add0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add0~2_combout\ = (s(1) & (!\Add0~1\)) # (!s(1) & ((\Add0~1\) # (GND)))
-- \Add0~3\ = CARRY((!\Add0~1\) # (!s(1)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => s(1),
	datad => VCC,
	cin => \Add0~1\,
	combout => \Add0~2_combout\,
	cout => \Add0~3\);

-- Location: FF_X15_Y1_N17
\s[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \Add0~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => s(1));

-- Location: LCCOMB_X15_Y1_N18
\Add0~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add0~4_combout\ = (s(2) & (\Add0~3\ $ (GND))) # (!s(2) & (!\Add0~3\ & VCC))
-- \Add0~5\ = CARRY((s(2) & !\Add0~3\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => s(2),
	datad => VCC,
	cin => \Add0~3\,
	combout => \Add0~4_combout\,
	cout => \Add0~5\);

-- Location: LCCOMB_X15_Y1_N20
\Add0~6\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add0~6_combout\ = (s(3) & (!\Add0~5\)) # (!s(3) & ((\Add0~5\) # (GND)))
-- \Add0~7\ = CARRY((!\Add0~5\) # (!s(3)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => s(3),
	datad => VCC,
	cin => \Add0~5\,
	combout => \Add0~6_combout\,
	cout => \Add0~7\);

-- Location: LCCOMB_X15_Y1_N10
\s~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \s~1_combout\ = (\Add0~6_combout\ & (((!\Equal0~0_combout\) # (!s(5))) # (!s(4))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => s(4),
	datab => s(5),
	datac => \Equal0~0_combout\,
	datad => \Add0~6_combout\,
	combout => \s~1_combout\);

-- Location: FF_X15_Y1_N11
\s[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \s~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => s(3));

-- Location: LCCOMB_X15_Y1_N4
\Equal0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Equal0~0_combout\ = (s(1) & (s(3) & (s(0) & !s(2))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => s(1),
	datab => s(3),
	datac => s(0),
	datad => s(2),
	combout => \Equal0~0_combout\);

-- Location: LCCOMB_X15_Y1_N22
\Add0~8\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add0~8_combout\ = (s(4) & (\Add0~7\ $ (GND))) # (!s(4) & (!\Add0~7\ & VCC))
-- \Add0~9\ = CARRY((s(4) & !\Add0~7\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => s(4),
	datad => VCC,
	cin => \Add0~7\,
	combout => \Add0~8_combout\,
	cout => \Add0~9\);

-- Location: LCCOMB_X15_Y1_N24
\Add0~10\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add0~10_combout\ = \Add0~9\ $ (s(5))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111111110000",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datad => s(5),
	cin => \Add0~9\,
	combout => \Add0~10_combout\);

-- Location: LCCOMB_X15_Y1_N0
\s~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \s~3_combout\ = (\Add0~10_combout\ & (((!s(5)) # (!\Equal0~0_combout\)) # (!s(4))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => s(4),
	datab => \Equal0~0_combout\,
	datac => s(5),
	datad => \Add0~10_combout\,
	combout => \s~3_combout\);

-- Location: FF_X15_Y1_N1
\s[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \s~3_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => s(5));

-- Location: LCCOMB_X15_Y1_N26
\s~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \s~2_combout\ = (\Add0~8_combout\ & (((!s(4)) # (!\Equal0~0_combout\)) # (!s(5))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => s(5),
	datab => \Equal0~0_combout\,
	datac => s(4),
	datad => \Add0~8_combout\,
	combout => \s~2_combout\);

-- Location: FF_X15_Y1_N27
\s[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \s~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => s(4));

-- Location: LCCOMB_X15_Y1_N12
\s~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \s~0_combout\ = (\Add0~4_combout\ & (((!\Equal0~0_combout\) # (!s(5))) # (!s(4))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => s(4),
	datab => s(5),
	datac => \Equal0~0_combout\,
	datad => \Add0~4_combout\,
	combout => \s~0_combout\);

-- Location: FF_X15_Y1_N13
\s[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \s~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => s(2));

-- Location: LCCOMB_X15_Y1_N28
\Equal0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Equal0~1_combout\ = (s(4) & (\Equal0~0_combout\ & s(5)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => s(4),
	datac => \Equal0~0_combout\,
	datad => s(5),
	combout => \Equal0~1_combout\);

-- Location: FF_X15_Y1_N29
sc : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \Equal0~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \sc~q\);

-- Location: CLKCTRL_G15
\sc~clkctrl\ : cycloneiv_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \sc~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \sc~clkctrl_outclk\);

-- Location: LCCOMB_X15_Y30_N18
\Add1~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add1~0_combout\ = m(0) $ (VCC)
-- \Add1~1\ = CARRY(m(0))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => m(0),
	datad => VCC,
	combout => \Add1~0_combout\,
	cout => \Add1~1\);

-- Location: FF_X15_Y30_N19
\m[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \sc~clkctrl_outclk\,
	d => \Add1~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => m(0));

-- Location: LCCOMB_X15_Y30_N20
\Add1~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add1~2_combout\ = (m(1) & (!\Add1~1\)) # (!m(1) & ((\Add1~1\) # (GND)))
-- \Add1~3\ = CARRY((!\Add1~1\) # (!m(1)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => m(1),
	datad => VCC,
	cin => \Add1~1\,
	combout => \Add1~2_combout\,
	cout => \Add1~3\);

-- Location: FF_X15_Y30_N21
\m[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \sc~clkctrl_outclk\,
	d => \Add1~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => m(1));

-- Location: LCCOMB_X15_Y30_N22
\Add1~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add1~4_combout\ = (m(2) & (\Add1~3\ $ (GND))) # (!m(2) & (!\Add1~3\ & VCC))
-- \Add1~5\ = CARRY((m(2) & !\Add1~3\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => m(2),
	datad => VCC,
	cin => \Add1~3\,
	combout => \Add1~4_combout\,
	cout => \Add1~5\);

-- Location: LCCOMB_X15_Y30_N24
\Add1~6\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add1~6_combout\ = (m(3) & (!\Add1~5\)) # (!m(3) & ((\Add1~5\) # (GND)))
-- \Add1~7\ = CARRY((!\Add1~5\) # (!m(3)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => m(3),
	datad => VCC,
	cin => \Add1~5\,
	combout => \Add1~6_combout\,
	cout => \Add1~7\);

-- Location: LCCOMB_X15_Y30_N30
\m~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \m~1_combout\ = (\Add1~6_combout\ & (((!m(0)) # (!m(1))) # (!\Equal1~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Equal1~0_combout\,
	datab => m(1),
	datac => m(0),
	datad => \Add1~6_combout\,
	combout => \m~1_combout\);

-- Location: FF_X15_Y30_N31
\m[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \sc~clkctrl_outclk\,
	d => \m~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => m(3));

-- Location: LCCOMB_X15_Y30_N26
\Add1~8\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add1~8_combout\ = (m(4) & (\Add1~7\ $ (GND))) # (!m(4) & (!\Add1~7\ & VCC))
-- \Add1~9\ = CARRY((m(4) & !\Add1~7\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => m(4),
	datad => VCC,
	cin => \Add1~7\,
	combout => \Add1~8_combout\,
	cout => \Add1~9\);

-- Location: LCCOMB_X15_Y30_N12
\m~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \m~2_combout\ = (\Add1~8_combout\ & (((!\Equal1~0_combout\) # (!m(1))) # (!m(0))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => m(0),
	datab => m(1),
	datac => \Add1~8_combout\,
	datad => \Equal1~0_combout\,
	combout => \m~2_combout\);

-- Location: FF_X15_Y30_N13
\m[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \sc~clkctrl_outclk\,
	d => \m~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => m(4));

-- Location: LCCOMB_X15_Y30_N28
\Add1~10\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add1~10_combout\ = \Add1~9\ $ (m(5))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111111110000",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datad => m(5),
	cin => \Add1~9\,
	combout => \Add1~10_combout\);

-- Location: LCCOMB_X15_Y30_N16
\m~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \m~3_combout\ = (\Add1~10_combout\ & (((!m(0)) # (!m(1))) # (!\Equal1~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Equal1~0_combout\,
	datab => m(1),
	datac => m(0),
	datad => \Add1~10_combout\,
	combout => \m~3_combout\);

-- Location: FF_X15_Y30_N17
\m[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \sc~clkctrl_outclk\,
	d => \m~3_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => m(5));

-- Location: LCCOMB_X15_Y30_N6
\Equal1~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Equal1~0_combout\ = (!m(2) & (m(5) & (m(3) & m(4))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => m(2),
	datab => m(5),
	datac => m(3),
	datad => m(4),
	combout => \Equal1~0_combout\);

-- Location: LCCOMB_X15_Y30_N10
\m~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \m~0_combout\ = (\Add1~4_combout\ & (((!\Equal1~0_combout\) # (!m(1))) # (!m(0))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => m(0),
	datab => m(1),
	datac => \Add1~4_combout\,
	datad => \Equal1~0_combout\,
	combout => \m~0_combout\);

-- Location: FF_X15_Y30_N11
\m[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \sc~clkctrl_outclk\,
	d => \m~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => m(2));

-- Location: LCCOMB_X15_Y30_N8
\Equal1~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Equal1~1_combout\ = (m(0) & (m(1) & \Equal1~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => m(0),
	datac => m(1),
	datad => \Equal1~0_combout\,
	combout => \Equal1~1_combout\);

-- Location: FF_X15_Y30_N9
mc : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \sc~clkctrl_outclk\,
	d => \Equal1~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \mc~q\);

-- Location: CLKCTRL_G10
\mc~clkctrl\ : cycloneiv_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \mc~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \mc~clkctrl_outclk\);

-- Location: LCCOMB_X26_Y30_N10
\Add2~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add2~0_combout\ = h(0) $ (VCC)
-- \Add2~1\ = CARRY(h(0))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => h(0),
	datad => VCC,
	combout => \Add2~0_combout\,
	cout => \Add2~1\);

-- Location: FF_X26_Y30_N11
\h[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \mc~clkctrl_outclk\,
	d => \Add2~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => h(0));

-- Location: LCCOMB_X26_Y30_N12
\Add2~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add2~2_combout\ = (h(1) & (!\Add2~1\)) # (!h(1) & ((\Add2~1\) # (GND)))
-- \Add2~3\ = CARRY((!\Add2~1\) # (!h(1)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => h(1),
	datad => VCC,
	cin => \Add2~1\,
	combout => \Add2~2_combout\,
	cout => \Add2~3\);

-- Location: FF_X26_Y30_N13
\h[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \mc~clkctrl_outclk\,
	d => \Add2~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => h(1));

-- Location: LCCOMB_X26_Y30_N14
\Add2~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add2~4_combout\ = (h(2) & (\Add2~3\ $ (GND))) # (!h(2) & (!\Add2~3\ & VCC))
-- \Add2~5\ = CARRY((h(2) & !\Add2~3\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => h(2),
	datad => VCC,
	cin => \Add2~3\,
	combout => \Add2~4_combout\,
	cout => \Add2~5\);

-- Location: FF_X26_Y30_N15
\h[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \mc~clkctrl_outclk\,
	d => \Add2~4_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => h(2));

-- Location: LCCOMB_X26_Y30_N16
\Add2~6\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add2~6_combout\ = (h(3) & (!\Add2~5\)) # (!h(3) & ((\Add2~5\) # (GND)))
-- \Add2~7\ = CARRY((!\Add2~5\) # (!h(3)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => h(3),
	datad => VCC,
	cin => \Add2~5\,
	combout => \Add2~6_combout\,
	cout => \Add2~7\);

-- Location: LCCOMB_X26_Y30_N18
\Add2~8\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Add2~8_combout\ = \Add2~7\ $ (!h(4))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datad => h(4),
	cin => \Add2~7\,
	combout => \Add2~8_combout\);

-- Location: LCCOMB_X26_Y30_N2
\h~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \h~1_combout\ = (\Add2~8_combout\ & ((!h(0)) # (!\Equal2~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \Equal2~0_combout\,
	datac => h(0),
	datad => \Add2~8_combout\,
	combout => \h~1_combout\);

-- Location: FF_X26_Y30_N3
\h[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \mc~clkctrl_outclk\,
	d => \h~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => h(4));

-- Location: LCCOMB_X26_Y30_N28
\Equal2~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Equal2~0_combout\ = (!h(3) & (h(1) & (h(2) & h(4))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => h(3),
	datab => h(1),
	datac => h(2),
	datad => h(4),
	combout => \Equal2~0_combout\);

-- Location: LCCOMB_X26_Y30_N8
\h~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \h~0_combout\ = (\Add2~6_combout\ & ((!h(0)) # (!\Equal2~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \Equal2~0_combout\,
	datac => h(0),
	datad => \Add2~6_combout\,
	combout => \h~0_combout\);

-- Location: FF_X26_Y30_N9
\h[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \mc~clkctrl_outclk\,
	d => \h~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => h(3));

ww_sout(0) <= \sout[0]~output_o\;

ww_sout(1) <= \sout[1]~output_o\;

ww_sout(2) <= \sout[2]~output_o\;

ww_sout(3) <= \sout[3]~output_o\;

ww_sout(4) <= \sout[4]~output_o\;

ww_sout(5) <= \sout[5]~output_o\;

ww_mout(0) <= \mout[0]~output_o\;

ww_mout(1) <= \mout[1]~output_o\;

ww_mout(2) <= \mout[2]~output_o\;

ww_mout(3) <= \mout[3]~output_o\;

ww_mout(4) <= \mout[4]~output_o\;

ww_mout(5) <= \mout[5]~output_o\;

ww_hout(0) <= \hout[0]~output_o\;

ww_hout(1) <= \hout[1]~output_o\;

ww_hout(2) <= \hout[2]~output_o\;

ww_hout(3) <= \hout[3]~output_o\;

ww_hout(4) <= \hout[4]~output_o\;
END structure;


