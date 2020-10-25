function check_Palindrome(str_entry){
    // Change the string into lower case and remove  all non-alphanumeric characters
       var cstr = str_entry.toLowerCase().replace(/[^a-zA-Z0-9]+/g,'');
        var ccount = 0;
    // Check if the string is empty or not
        if(cstr==="") {
            console.log("Nothing found!");
            return false;
        }
    //  if the length of the string is even or odd checking
        if ((cstr.length) % 2 === 0) {
            ccount = (cstr.length) / 2;
        } else {
    // If the length of the string is 1 then it becomes a palindrome
            if (cstr.length === 1) {
                console.log("Entry is a palindrome.");
                return true;
            } else {
    // If the length of the string is odd ignore middle character
                ccount = (cstr.length - 1) / 2;
            }
        }
    // Loop through to check the first character to the last character and then move next
        for (var x = 0; x < ccount; x++) {
    // Compare characters and drop them if they do not match 
            if (cstr[x] != cstr.slice(-1-x)[0]) {
                console.log("Entry is not a palindrome.");
                return false;
            }
        }
        console.log("The entry is a palindrome.");
        return true;
    }
    check_Palindrome('return')
    check_Palindrome('madam');
    check_Palindrome('malayalam');
    check_Palindrome('      ');