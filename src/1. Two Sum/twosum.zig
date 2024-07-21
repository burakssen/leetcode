const std = @import("std");

pub fn two_sum(array: []i32, target: i32) ![]i32 {
    const allocator = std.heap.page_allocator;
    var map = std.AutoHashMap(i32, usize).init(allocator);
    defer map.deinit();

    // Iterate through the array with the index
    for (array, 0..) |value, index| {
        // Calculate the complement of the current value
        const complement = target - value;

        // Check if the complement exists in the map
        if (map.get(complement)) |comp_index| {
            // Create a fixed-size array to hold the result
            var result: [2]i32 = .{ @as(i32, @intCast(comp_index)), @as(i32, @intCast(index)) };

            // Create a slice from the fixed-size array and return it
            return result[0..];
        }

        // Insert the current value and its index into the map
        try map.put(value, index);
    }

    // If no solution is found, return an error
    return error.NoTwoSum;
}

pub const Error = error{NoTwoSum};
