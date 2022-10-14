// C function to find the largest element in an array, recursively.
// Returns the value of the largest element in the array.
// 
// array:  Array to search
// length: Number of elements in the array
int max(int array[], int length) {
    // 
    int first_element = array[0];
    if (length == 1) {
        // Handle the base-case of the recursion, at the end of the array.
        return first_element;
    } else {
        // Recurse on the rest of the array.
        // Finds the largest element after first_element in the array.
        int max_so_far = max(&array[1], length - 1);

        // Compare this element with the largest element after it in the array.
        if (first_element > max_so_far) {
            max_so_far = first_element;
        }
        return max_so_far;
    }
}



/*
int max(array=[3, 1, 2], length=3) {
    // 
    int first_element = 3;
    if (length == 1) {
        // Handle the base-case of the recursion, at the end of the array.
        return first_element;
    } else {
        // Recurse on the rest of the array.
        // Finds the largest element after first_element in the array.
        int max_so_far = max([1, 2], 2)
        int first_element = 1;
        if (length == 1) {
            return first_element;
        } else {
            int max_so_far = max([2], 1) (=2)
            if (first_element > max_so_far) {
                max_so_far = first_element;
            }
        }
        // first element is 3
        // Compare this element with the largest element after it in the array.
        if (first_element > max_so_far) {
            max_so_far = first_element;
        }
        return max_so_far;
    }
}

*/