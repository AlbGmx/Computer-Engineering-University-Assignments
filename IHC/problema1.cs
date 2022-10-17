/*
   Dado un arreglo de números enteros nums, para cada elemento nums[ i ] encontrar cuántos números en el arreglo son menores que dicho elemento. 
   Regresar el resultado en un arreglo. 
   Ejemplo.
   Input: nums = [8,1,2,2,3] 
   Output: [4,0,1,1,3] 
*/

using System;

class Problema1
{
    static void Main()
    {
        int[] nums = { 8, 1, 2, 2, 3 };
        int[] result = new int[nums.Length];
        int count = 0;

        for (int i = 0; i < nums.Length; i++)
        {
            for (int j = 0; j < nums.Length; j++)
            {
                if (nums[i] > nums[j])
                {
                    count++;
                }
            }
            result[i] = count;
            count = 0;
        }

        for (int i = 0; i < result.Length; i++)
        {
            Console.Write(result[i] + " ");
        }
    }
}