011011"""
Lab 5: Working of S-Box (DES)
"""

# DES S-Box 1
S_BOX_1 = [
    [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
    [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
    [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
    [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]
]

def sbox_substitution(input_bits):
    """
    Perform S-box substitution
    Input: 6-bit binary string
    Output: 4-bit binary string
    """
    if len(input_bits) != 6 or not all(bit in '01' for bit in input_bits):
        print("Invalid input! Enter exactly 6 bits.")
        return None

    # Row = 1st and last bit
    row = int(input_bits[0] + input_bits[5], 2)

    # Column = middle 4 bits
    col = int(input_bits[1:5], 2)

    # Lookup S-box value
    value = S_BOX_1[row][col]

    # Convert to 4-bit binary
    return format(value, '04b')

# Main Program
print("S-Box Working")
bits = input("Enter 6-bit binary input: ")
output = sbox_substitution(bits)

if output:
    print("Output (4 bits):", output)
