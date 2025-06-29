library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ContadorModuloM_tb is
end ContadorModuloM_tb;

architecture Behavioral of ContadorModuloM_tb is
    constant M : integer := 12;     --Modulo 12(0 -11)
    constant N : integer := 14;
    constant T: time     := 20 ns;  --Periodo
    
    signal clk, rst : std_logic;
    signal tc : std_logic;
    signal conteo : std_logic_vector(N-1 downto 0);
begin
    uut : entity work.ContadorModuloM -- "Instancion por Entidad" en lugar de "Instacion por Componente",
        generic map (                 -- la palabra "work" se refiere a la biblioteca o directorio de trabajo actual,
            M => M,                   -- usando "entity work,ContadorModuloM" no es necesario agregar el componente
            N => N                    -- (component ContadorModuloM), a diferencia de como se hizo en "medio_sumador_tb.vhd".
            )
       port map (
            clk    => clk,
            rst    => rst,
            tc     => tc,
            conteo => conteo
            );
process
begin
            clk <= '0';
            wait for T/2;
            clk <= '1';
            wait for T/2; -- Ciclo de trabajo de 50%.
        end process;
        -- rst activo solo en el primer ciclo de reloj.
        rst <= '1', '0' after T/2;
end Behavioral;
