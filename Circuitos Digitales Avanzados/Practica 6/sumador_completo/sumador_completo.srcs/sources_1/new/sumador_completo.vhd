----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/27/2021 02:15:18 PM
-- Design Name: 
-- Module Name: sumador_completo - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity sumador_completo is
    Port ( a : in STD_LOGIC;
           b : in STD_LOGIC;
           c : in std_logic;
           suma : out STD_LOGIC;
           acarreo : out STD_LOGIC);
end sumador_completo;

architecture Behavioral of sumador_completo is

begin
    suma <= a xor b xor c;
    acarreo <= (a and b) or ((a or b) and (c));
end Behavioral;
