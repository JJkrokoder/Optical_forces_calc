# This code is for testing a function that calculates the radiative normalized polarizability of a molecule

import numpy as np

def test_polarizability(quasiestatic_polarizability, lambda_nm):
    '''
    This function tests the polarizability function

    Parameters
    ----------
    quasiestatic_polarizability : float
        The calculated polarizability of the molecule from Clausius-Mossotti relation in nm^3
    lambda_nm : float
        The wavelength of light in nm

    Returns
    -------
    polarizability : float
        The calculated polarizability of the molecule from the function
    '''

    # wave number of light in nm^-1
    k = 2 * np.pi / lambda_nm

    # polarizability in nm^3
    polarizability = quasiestatic_polarizability / (1 - 2 * 1j* quasiestatic_polarizability * k**3/3)

    assert np.isclose(polarizability, quasiestatic_polarizability / (1 - 2 * 1j* quasiestatic_polarizability * k**3/3))

    return polarizability

