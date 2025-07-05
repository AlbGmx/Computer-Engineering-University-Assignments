library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
entity ContadorModuloM is
    generic (
            M : integer := 5; -- Conteo de 0 a M-1.
            N : integer := 3  -- Numero de bits requeridos para el conteo
    );
    port (
            clk, rst : in std_logic;
            tc       : out std_logic; -- Ciclo de conteo terminado.
            conteo   : out std_logic_vector(N-1 downto 0)
    );
end ContadorModuloM;
architecture Behavioral of ContadorModuloM is
    signal cnt, cnt_siguiente : unsigned(N-1 downto 0);
begin
    process(clk, rst)
    begin
        if rst = '1' then
            cnt <= (others=>'0');
        elsif rising_edge(clk) then
            cnt <= cnt_siguiente;
        else
            cnt <= cnt;
        end if;
    end process;

    -- Si el conteo actual es M-1, el siguiente debe ser 0. De otra manera, incrementar
    -- el conteo actual.
    cnt_siguiente <= (others=>'0') when cnt=(M-1) else (cnt+1);

    -- Activar Tc cuando se llega al conteo maximo.
    tc <= '1' when cnt = (M-1) else '0';

    conteo <= std_logic_vector(cnt); -- Conteo actual en el puerto de salida.
end Behavioral;