/**
 * You can edit, run, and share this code.
 * play.kotlinlang.org
 */
fun main() {
    val testNumb = listOf(2, 4, 6, 8, -1, 30, 1, 2, 3, 4, 5)
    println("Hello, world!!!")
    val sum = calcSum(testNumb)
    println("Sum = $sum")
}

fun calcSum(input: List<Int>): Int {
    // TODO: handle empty input
    var sum = 0
    for (elem in input) {
        sum += elem
    }
    return sum
}
