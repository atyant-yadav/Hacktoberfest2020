function isPalindrome(word){
	var len = string.length;
	for(var i = 0; i < len/2; i++){
		if (word[i] !== string[len - 1 - i]) {
			alert('not a palindrome');
		}
	}
	alert('This is a Palindorme!');
}
