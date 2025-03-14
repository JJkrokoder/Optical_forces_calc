# validate_force_ratios.py
"""
This script generates a validation plot for the optical forces calculation by:
1. Reading force data from an input file with format:
   # Permittivity | Particle | Fx | Fy | Fz
2. Computing the ratio of forces F(ε₁)/F(ε₂) vs ratio of permittivities ε₁/ε₂
3. Plotting these ratios for each particle against the theoretical y=x line
4. If points fall on the y=x line, it confirms the linear relationship 
   between forces and permittivity predicted by dipole approximation
"""

import numpy as np
import matplotlib.pyplot as plt
import sys
import os

def validate_file_format(filename):
    try:
        # Check if file exists
        if not os.path.exists(filename):
            raise FileNotFoundError(f"File {filename} not found")
            
        # Read first line to check header format
        with open(filename, 'r') as f:
            header = f.readline().strip()
            if not header.startswith("# Permittivity | Particle | Fx | Fy | Fz"):
                raise ValueError("Invalid file format: Header must be '# Permittivity | Particle | Fx | Fy | Fz'")
            
        # Try to load data and check structure
        data = np.loadtxt(filename, comments='#')
        if data.shape[1] != 5:  # Should have 5 columns
            raise ValueError("Invalid file format: Each line must have 5 columns")
            
        return data
    except Exception as e:
        print(f"Error: {str(e)}")
        sys.exit(1)

def plot_force_ratios(data):
    permittivities = np.unique(data[:,0])
    particles = np.unique(data[:,1]).astype(int)
    
    fig, ax = plt.subplots()
    
    for p in particles:
        # Get forces for this particle
        particle_data = data[data[:,1] == p]
        forces = particle_data[:,2]  # Using Fx as example
        
        # Calculate ratios
        force_ratios = forces[1:] / forces[:-1]
        perm_ratios = permittivities[1:] / permittivities[:-1]
        
        # Plot
        ax.plot(perm_ratios, force_ratios, 'o', label=f'Particle {p}')
    
    # y=x line for comparison
    ax.plot([1, max(perm_ratios)], [1, max(perm_ratios)], 'k--', label='Theoretical')
    
    ax.set_xlabel('ε₁/ε₂')
    ax.set_ylabel('F(ε₁)/F(ε₂)')
    ax.legend()
    plt.title('Validation of Force-Permittivity Ratio')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <forces_file>")
        sys.exit(1)
        
    input_file = sys.argv[1]
    data = validate_file_format(input_file)
    plot_force_ratios(data)