import math

def f(x):
    """Function f(x) = x^3 + 4x^2 - 10"""
    return x**3 + 4*x**2 - 10

def bisection_method(a, b, tolerance, max_iterations=100):
    """
    Bisection method to find root of f(x) = 0
    
    Parameters:
    a, b: interval [a, b] containing the root
    tolerance: desired accuracy
    max_iterations: maximum number of iterations
    
    Returns:
    root approximation and table data
    """
    
    # Check if f(a) and f(b) have opposite signs
    if f(a) * f(b) >= 0:
        print("Error: f(a) and f(b) must have opposite signs")
        return None, None
    
    # Initialize table data
    table_data = []
    iteration = 0
    prev_p = None
    
    print("=" * 105)
    print(f"| {'Iter':^6} | {'a_n':^12} | {'b_n':^12} | {'p_n':^12} | {'f(a_n)':^14} | {'f(p_n)':^14} | {'Rel Error':^14} |")
    print("-" * 105)
    
    while iteration < max_iterations:
        # Calculate midpoint
        p = (a + b) / 2
        
        # Calculate relative error
        if prev_p is not None:
            relative_error = abs((p - prev_p) / p)
        else:
            relative_error = 0
        
        # Store data for this iteration
        table_data.append({
            'iteration': iteration,
            'a': a,
            'b': b,
            'p': p,
            'f_a': f(a),
            'f_p': f(p),
            'rel_error': relative_error
        })
        
        # Print row with proper formatting
        print(f"| {iteration:^6d} | {a:^12.6f} | {b:^12.6f} | {p:^12.6f} | {f(a):^14.6f} | {f(p):^14.6f} | {relative_error:^14.6f} |")
        
        # Check if we've reached the desired accuracy
        if iteration > 0 and relative_error < tolerance:
            print("-" * 105)
            print(f"\nRoot found: {p:.6f} after {iteration + 1} iterations")
            print(f"Relative error: {relative_error:.6f} (less than {tolerance})")
            return p, table_data
        
        # Update interval
        if f(a) * f(p) < 0:
            b = p
        else:
            a = p
        
        prev_p = p
        iteration += 1
    
    print("-" * 90)
    print(f"\nMaximum iterations ({max_iterations}) reached")
    print(f"Approximate root: {p:.6f}")
    print(f"Relative error: {relative_error:.6f}")
    return p, table_data

# Main execution
def main():
    # Show that f(x) has a root in [1, 2]
    a = 1
    b = 2
    
    print("Showing that f(x) = x^3 + 4x^2 - 10 has a root in [1, 2]:")
    print(f"f(1) = {f(1):.6f}")
    print(f"f(2) = {f(2):.6f}")
    print(f"Since f(1) < 0 and f(2) > 0, by the Intermediate Value Theorem,")
    print(f"there exists a root in the interval [1, 2]\n")
    
    # Apply bisection method
    tolerance = 1e-6
    root, table = bisection_method(a, b, tolerance)
    
    # Verify the root
    if root is not None:
        print(f"\nVerification:")
        print(f"f({root:.6f}) = {f(root):.12f}")
        print(f"Error: |f({root:.6f})| = {abs(f(root)):.12f}")

if __name__ == "__main__":
    main()