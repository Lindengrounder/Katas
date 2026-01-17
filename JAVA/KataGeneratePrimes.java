// Пример со страницы 98 книги "Чистый Код" Роберта Мартина.
// Добавлен класс main для запуска в режиме одного файла
// протестировано https://www.jdoodle.com/online-java-compiler
// последний тест: 17.01.2026
import java.util.*;

public class KataGeneratePrimes
{
  public static void main (String[] args)
  {
    int[] primes = GeneratePrimes.generatePrimes(366);
    System.out.println(Arrays.toString(primes));
  }
}

class GeneratePrimes
{
  // @param maxValue - верхняя граница диапазона.
  public static int [] generatePrimes (int maxValue)
  {
    if (maxValue >= 2)
    {
      int s = maxValue +1; // Размер массива
      boolean [] f = new boolean [s];
      int i;

    // Инициализировать массив значениями true
    for (i=0; i<s; i++)
      f[i] = true;
    f[0] = f[1] = false;

    int j;
    for (i=2; i< Math.sqrt(s) +1; i++)
    {
      if (f[i])
      {
        for (j=2*i; j<s; j +=i)
          f[j] = false;
      }
    }

    int count = 0;
    for (i=0; i<s; i++)
    {
      if (f[i])
        count++;
    }

    int[] primes = new int[count];

    for (i=0, j=0; i<s; i++)
      {
        if (f[i])
          primes[j++] = i;
      }

    return primes;
    }
    else
      return new int[0]; //Вернуть пустой массив при  недопустимых входных данных.
  }
}
