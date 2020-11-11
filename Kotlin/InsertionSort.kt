/**
 * Perform insertion sort using kotlin
 */

fun insertionSort(arr: IntArray): IntArray {
    for(i in arr.indices){
        val key = arr[i]
        var j = i - 1

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j]
            j -= 1
        }

        arr[j + 1] = key
    }
    return arr
}

fun main() {
    val arr = IntArray(20)
    for (i in arr.indices) {
        arr[i] = (Math.random() * 999 + 1).toInt()
    }
    print(insertionSort(arr).joinToString())
}
