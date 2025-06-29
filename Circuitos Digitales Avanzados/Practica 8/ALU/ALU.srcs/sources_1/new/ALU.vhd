----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 12/15/2020 06:44:30 PM
-- Design Name: 
-- Module Name: ALU - Behavioral
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
-- use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;
entity ALU is
  generic ( 
     constant N: natural := 1;  -- number of shited or rotated bits
     constant nBits: integer := 32
    );
    Port (
    A, B    : in   STD_LOGIC_VECTOR(nbits-1 downto 0);  -- 2 inputs 32-bit
    ALU_Opc     : in   STD_LOGIC_VECTOR(3 downto 0);  -- 1 input 4-bit for selecting function
    ALU_Out : out  STD_LOGIC_VECTOR(nBits-1 downto 0); -- 1 output 32-bit 
    Cout    : out  std_logic;        -- Carry Out flag
    Cin     : in   std_logic;
    Parity  : out  std_logic;
    Overflow: out  std_logic;
    Zero    : out  std_logic 
    );
end ALU; 

architecture Behavioral of ALU is

signal tmp : std_logic_vector (nBits downto 0);
signal temp2 : std_logic_vector (nBits-1 downto 0);
signal temp3 : std_logic_vector (nBits-1 downto 0);
signal temp4 : std_logic_vector (nBits downto 0);

begin
   process(A,B,ALU_Opc, Cin)
 begin
  case(ALU_Opc) is
  when "0000" => -- Logical and 
   ALU_Out <= A and B;
  when "0001" => -- Logical or
   ALU_Out <= A or B;
  when "0010" => -- Logical xor 
   ALU_Out <= A xor B;
  when "0011" => -- Logical not
   ALU_Out <= not A;
  when "0100" => -- Addition
   ALU_Out <= A + B ; 
  when "0101" => -- Addition with carry
   ALU_Out <= A + B + Cin; 
  when "0110" => -- Subtraction
   ALU_Out <= A - B - Cin ;  
  when "0111" => -- Subtraction with carry
   ALU_Out <= A - B  ;
  when "1000" => -- Inc A
   ALU_Out <= A + 1 ; 
  when "1001" => -- Dec A
   ALU_Out <= A - 1 ;
  when "1010" => -- Logical shift left
   ALU_Out <= std_logic_vector(unsigned(A) sll N);
  when "1011" => -- Logical shift right
   ALU_Out <= std_logic_vector(unsigned(A) srl N);
  when "1100" => --  Rotate left
   ALU_Out <= std_logic_vector(unsigned(A) rol N);
  when "1101" => -- Rotate right
   ALU_Out <= std_logic_vector(unsigned(A) ror N);
  when others => ALU_Out <= A + B ; 
  end case;
 end process;
 
 tmp <= ('0' & A) + ('0' & B);
 Cout <= tmp(8); -- Cout flag 
 Overflow <= tmp(8); -- Ov flag

end Behavioral;