# This is the setup file for the package. The scripts are in the src/OFC_utils folder

from setuptools import setup, find_packages

#install the package

setup(
        
        name='OFC_utils',
        version='1.0',
        description='Utilities for Optical Forces calculations',
        author='Joan Ronquillo',
    
        #
        packages=find_packages('src'),
        package_dir={'': 'src'},
        )

