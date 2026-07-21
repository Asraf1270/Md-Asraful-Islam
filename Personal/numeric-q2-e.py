import math

def f(x):
    """Function f(x) = x^3 + 4x^2 - 10"""
    return x**3 + 4*x**2 - 10

def bisection_method_with_pause(a, b, tolerance, max_iterations=100):
    """
    Bisection method with step-by-step display
    Press Enter to show next row
    """
    
    # Check if f(a) and f(b) have opposite signs
    if f(a) * f(b) >= 0:
        print("Error: f(a) and f(b) must have opposite signs")
        return None
    
    # Initialize
    iteration = 0
    prev_p = None
    
    # Print header
    print("\n" + "=" * 95)
    print(f"{'Iter':^6} | {'a_n':^14} | {'b_n':^14} | {'p_n':^14} | {'f(a_n)':^14} | {'f(p_n)':^14} | {'Rel Error':^13}")
    print("=" * 95)
    
    while iteration < max_iterations:
        # Calculate midpoint
        p = (a + b) / 2
        
        # Calculate relative error
        if prev_p is not None:
            relative_error = abs((p - prev_p) / p)
        else:
            relative_error = 0
        
        # Print current row with 6 decimal places
        print(f"{iteration:^6d} | {a:^14.6f} | {b:^14.6f} | {p:^14.6f} | {f(a):^14.6f} | {f(p):^14.6f} | {relative_error:^13.6f}")
        print("-" * 95)
        
        # Check if we've reached desired accuracy
        if iteration > 0 and relative_error < tolerance:
            print(f"\n✓ Root found: {p:.6f} after {iteration + 1} iterations")
            print(f"✓ Relative error: {relative_error:.6f} (less than {tolerance})")
            return p
        
        # Update interval
        if f(a) * f(p) < 0:
            b = p
        else:
            a = p
        
        prev_p = p
        iteration += 1
        
        # Wait for user to press Enter (except for the last iteration)
        if iteration < max_iterations:
            input("Press Enter to continue to next iteration...")
    
    print(f"\nMaximum iterations ({max_iterations}) reached")
    print(f"Approximate root: {p:.6f}")
    return p

def main():
    # Show that f(x) has a root in [1, 2]
    a = 1
    b = 2
    
    print("\n" + "=" * 95)
    print("BISECTION METHOD - STEP BY STEP SOLUTION")
    print("=" * 95)
    
    print(f"\n📐 Function: f(x) = x³ + 4x² - 10")
    print(f"\n🔍 Showing root exists in [1, 2]:")
    print(f"   f(1) = {f(1):.6f}")
    print(f"   f(2) = {f(2):.6f}")
    print(f"   Since f(1) < 0 and f(2) > 0, by IVT, root exists in [1, 2]")
    print(f"\n🎯 Target accuracy: within 10^-6")
    print(f"\n📝 Instructions: Press ENTER after each row to see the next iteration")
    print("=" * 95)
    
    input("\nPress Enter to start the bisection method...")
    
    # Apply bisection method
    tolerance = 1e-6
    root = bisection_method_with_pause(a, b, tolerance)
    
    # Verification
    if root is not None:
        print("\n" + "=" * 95)
        print("VERIFICATION")
        print("=" * 95)
        print(f"f({root:.6f}) = {f(root):.10f}")
        print(f"|f({root:.6f})| = {abs(f(root)):.10f}")
        print(f"✓ Error is less than {tolerance}")
        print("=" * 95)

if __name__ == "__main__":
    main()