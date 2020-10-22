//Given two strings, return true if they are anagrams of one another

	let first;
	let second;

	function isAnagram(first, second){
		let a = first.toLowerCase();
		let b = second.toLowerCase();
		a = a.split(“”).sort()/join(“”);
		b = b.split(“”).sort().join(“”);

		return a === b;
	}
