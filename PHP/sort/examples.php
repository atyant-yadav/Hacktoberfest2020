echo "<pre>";
echo "<br>", "Bubble Sorting - 1, 99, 3, 77, 5, 998, 7, 45, 32", "<br>";
$arr = array(1, 99, 3, 77, 5, 998, 7, 45, 32);
$reuslt = bubbleSort($arr);
print_r($reuslt);
 
echo "<br>", "Merge Sorting - 6, 5, 3, 1, 8, 7, 9, 2, 4", "<br>";
$arr = array(6, 5, 3, 1, 8, 7, 9, 2, 4);
$reuslt = mergeSort($arr);
print_r($reuslt);
 
echo "<br>", "Quick Sorting - 1, 99, 87, 2, 5, 9, 1999, 899, 777", "<br>";
$arr = array(1, 99, 87, 2, 5, 9, 1999, 899, 777);
$reuslt = quickSort($arr);
print_r($reuslt);
