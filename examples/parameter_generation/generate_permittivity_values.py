import numpy as np
import argparse
import os

def generate_permittivity_values(output_file, n_values=20, min_value=1.0, max_value=10.0, log_scale=False):
    """
    Genera un archivo con valores de permitividad para pruebas.
    
    Args:
        output_file (str): Ruta del archivo de salida
        n_values (int): Número de valores a generar
        min_value (float): Valor mínimo de permitividad
        max_value (float): Valor máximo de permitividad
        log_scale (bool): Si True, genera valores en escala logarítmica
    """
    if log_scale:
        values = np.logspace(np.log10(min_value), np.log10(max_value), n_values)
    else:
        values = np.linspace(min_value, max_value, n_values)
    
    # Crear directorio si no existe
    os.makedirs(os.path.dirname(output_file), exist_ok=True)
    
    # Guardar valores en archivo
    with open(output_file, 'w') as f:
        f.write("# Valores de permitividad para pruebas\n")
        f.write("# índice valor_permitividad\n")
        for i, value in enumerate(values):
            f.write(f"{i}\t{value:.6f}\n")

def main():
    parser = argparse.ArgumentParser(description='Genera valores de permitividad para pruebas')
    parser.add_argument('--output', type=str, default='../test_data/permittivity_values.txt',
                      help='Ruta del archivo de salida')
    parser.add_argument('--n-values', type=int, default=20,
                      help='Número de valores a generar')
    parser.add_argument('--min-value', type=float, default=1.0,
                      help='Valor mínimo de permitividad')
    parser.add_argument('--max-value', type=float, default=10.0,
                      help='Valor máximo de permitividad')
    parser.add_argument('--log', action='store_true',
                      help='Usar escala logarítmica en lugar de lineal')
    
    args = parser.parse_args()
    
    generate_permittivity_values(
        args.output,
        args.n_values,
        args.min_value,
        args.max_value,
        args.log
    )
    
    print(f"Valores de permitividad generados en: {args.output}")

if __name__ == "__main__":
    main()