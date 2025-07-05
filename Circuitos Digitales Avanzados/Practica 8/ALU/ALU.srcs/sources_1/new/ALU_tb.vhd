----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 12/15/2020 07:00:01 PM
-- Design Name: 
-- Module Name: ALU_tb - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.NUMERIC_STD.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;
 
ENTITY tb_ALU IS
END tb_ALU;
 
ARCHITECTURE behavior OF tb_ALU IS 
      constant nBits: integer := 32;
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ALU    

    PORT(  
         A       : IN   std_logic_vector(nBits-1 downto 0);
         B       : IN   std_logic_vector(nBits-1 downto 0);
         ALU_Opc : IN   std_logic_vector(3 downto 0);
         ALU_Out : out  std_logic_vector(nBits-1 downto 0);
         Cout    : out  std_logic;
         Cin     : in   std_logic;
         Parity  : out  std_logic;
         Overflow: out  std_logic;
         Zero    : out  std_logic 
         );
   END COMPONENT;
       --Inputs
   signal A       : std_logic_vector(nBits-1 downto 0) := (others => '0');
   signal B       : std_logic_vector(nBits-1 downto 0) := (others => '0');
   signal ALU_Opc : std_logic_vector(3 downto 0)       := (others => '0');
   signal Cin     : std_logic;
        --Outputs
   signal ALU_Out : std_logic_vector(nBits-1 downto 0);
   signal Cout    : std_logic;
   signal Parity  : std_logic;
   signal Overflow: std_logic;
   signal Zero    : std_logic;
   signal i       : integer;
BEGIN
 
 -- Instantiate the Unit Under Test (UUT)
   uut: ALU PORT MAP (
          A        => A,
          B        => B,
          ALU_Opc  => ALU_Opc,
          ALU_Out  => ALU_Out,
          Cout     => Cout,
          Cin      => Cin,
          Parity   => Parity,
          Overflow => Overflow,
          Zero     => Zero
        );

   -- Stimulus process
   stim_proc: process
   begin     
   A <= x"12345678";
   B <= x"FEDCBA98";
   ALU_Opc <= x"0";
   Cin <= '1';
   Zero <= '0';
   Parity <= '0';
   Overflow <= '0';
   wait for 100 ns;
   for i in 0 to 15 loop 
    ALU_Opc <= ALU_Opc + x"1";
    if ALU_Out = x"0" then
       Zero <= '1';
    else 
       Zero <= '0';
    end if;
    wait for 50 ns;
   end loop;
   A <= x"55555555";
   B <= x"AAAAAAAA";
   wait;
   end process;
END;