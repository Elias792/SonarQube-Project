#ifndef INSECURE_UTILS_H
#define INSECURE_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Copie la chaîne d'entrée dans un buffer de taille restreinte,
 *        sans aucun contrôle de longueur (possible overflow).
 */
char* insecure_copy(const char* input);

/**
 * @brief Construit une string via sprintf (sans contrôle de format)
 *        et l'affiche. Peut générer un overflow ou injection.
 */
void insecure_print_format(const char* data);

#ifdef __cplusplus
}
#endif

#endif /* INSECURE_UTILS_H */
