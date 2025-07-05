----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/27/2021 04:33:15 PM
-- Design Name: 
-- Module Name: Sumador_Serie_tb - Behavioral
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
use IEEE.NUMERIC_STD.ALL;
entity Sumador_Serie_tb is
end Sumador_Serie_tb;

architecture Behavioral of Sumador_Serie_tb is
    constant N : integer := 5;
    constant T : time := 100ns;
    signal clk, rst, load, a, b, c, cin, cout : std_logic;
    signal numA, numB, numC                   : std_logic_vector(N-1 downto 0); 

begin
    FlipFlopD : entity work.FlipFlopD
        port map(
            clk => clk,
            rst => rst,
            d => cout,
            q => cin
        );
    RegistroA : entity work.RegistroDesplazamiento
        generic map ( N => N)
        port map(
            clk => clk,
            rst => rst,             
            load => load,
            din => numA,
            dout => a,
            d => '1'
        );    
    RegistroB : entity work.RegistroDesplazamiento
        generic map ( N => N)
        port map (
            clk => clk,
            rst => rst,             
            load => load,
            din => numB,
            dout => b,
            d => '1'
        );
    RegistroC : entity work.RegistroDesplazamiento
        generic map ( N => N)
        port map (
            clk => clk,
            rst => rst,
            load => load,
            din => numC,
            d => c,
            numOut => numC 
        );
    SumadorSerie : entity work.SumadorSerie
        port map(
            a => a,
            b => b,
            s => c,
            cin => cin,
            cout => cout
        );
            numA <= "01000" after T/2;
            numB <= "00011" after T/2;
            rst <= '1' after T/2, '0' after T;
            load <= '1' after T/2, '0' after 2*T;
    process
    begin
        clk <= '0';
        wait for T/2;
        clk <= '1';
        wait for T/2;
    end process;
end Behavioral;
