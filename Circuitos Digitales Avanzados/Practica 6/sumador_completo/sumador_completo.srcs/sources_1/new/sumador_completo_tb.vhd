----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/27/2021 02:19:26 PM
-- Design Name: 
-- Module Name: sumador_completo_tb - Behavioral
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
entity sumador_completo_tb is
-- port ();
end sumador_completo_tb;

architecture behavioural of sumador_completo_tb is
    -- Componente
    component sumador_completo
    Port ( 
           a : in STD_LOGIC;
           b : in STD_LOGIC;
           c : in STD_LOGIC;
           suma : out STD_LOGIC;
           acarreo : out STD_LOGIC
    );
    end component;
    -- Señales
    signal s_a  :   std_logic := '0';
    signal s_b  :   std_logic := '0';
    signal s_c  :   std_logic := '0';
    signal s_suma  :   std_logic;
    signal s_acarreo  :   std_logic;
    -- Instanciacion
  begin
    uut : sumador_completo
    port map(
        a => s_a,
        b => s_b,
        c => s_c,
        suma => s_suma,
        acarreo => s_acarreo
        );
    process is
    begin 
        s_a <= '0';
        s_b <= '0';
        s_c <= '0';
        wait for 100 ns;
        s_a <= '0';
        s_b <= '0';
        s_c <= '1';
        wait for 100 ns;
        s_a <= '0';
        s_b <= '1';
        s_c <= '0';
        wait for 100 ns;
        s_a <= '0';
        s_b <= '1';
        s_c <= '1';
        wait for 100 ns;
        s_a <= '1';
        s_b <= '0';
        s_c <= '0';
        wait for 100 ns;
        s_a <= '1';
        s_b <= '0';
        s_c <= '1';
        wait for 100 ns;
        s_a <= '1';
        s_b <= '1';
        s_c <= '0';
        wait for 100 ns;
        s_a <= '1';
        s_b <= '1';
        s_c <= '1';
        wait for 100 ns;
    end process;
  end behavioural;