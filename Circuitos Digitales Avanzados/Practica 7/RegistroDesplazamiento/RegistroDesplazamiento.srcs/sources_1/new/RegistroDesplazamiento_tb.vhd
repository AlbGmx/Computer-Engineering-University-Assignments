library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity RegistroDesplazamiento_tb is
end RegistroDesplazamiento_tb;
architecture Behavioral of RegistroDesplazamiento_tb is
    constant N: integer := 4;
    constant T: time := 20ns;

    signal clk, rst, load, d: std_logic ;
    signal din: std_logic_vector(N-1 downto 0);
    signal dout: std_logic_vector(N-1 downto 0);

begin
    uut: entity work.RegistroDesplazamiento
    generic map(
        N=>N
    )
    port map(
        clk => clk,
        rst => rst,
        load => load,
        din => din,
        dout => dout,
        d => d
    );
    process
    begin
        clk <= '0';
        wait for T/2;
        clk <= '1';
        wait for T/2;
    end process;
    din <= "0111";
    rst <= '1','0' after T/2;
    load <= '0','1' after T, '0' after 2*T;
    d<='0','1' after T, '0' after 2*T,'1' after 4*T,'0' after 150ns;
end Behavioral;
