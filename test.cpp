#include "inc/game.hpp"

// Dimensions de la carte
const int mapWidth = 10;
const int mapHeight = 10;

// Carte 2D
char map[mapHeight][mapWidth] = {
    {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
    {'G', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'G', 'G'},
    {'G', 'W', 'G', 'W', 'G', 'G', 'G', 'G', 'G', 'G'},
    {'G', 'W', 'G', 'W', 'W', 'W', 'G', 'G', 'G', 'G'},
    {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
    {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
    {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
    {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
    {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
    {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'}
};

// Taille des tuiles
const int tileSize = 32;

int main() {
    // Initialisation de la fenêtre
    InitWindow(800, 600, "Carte 2D avec Raylib");

    // Chargement des textures
    Texture2D grassTexture = LoadTexture("asset/texture/ground_1.png");
    Texture2D waterTexture = LoadTexture("asset/texture/wall_1.png");

    // Position initiale du personnage
    Vector2 playerPosition = {5 * tileSize, 5 * tileSize};

    // Configuration de la caméra
   Camera2D camera ;
camera.target = {0.0f, 0.0f};
camera.offset = {400.0f, 300.0f};
camera.rotation = 0.0f;
camera.zoom = 1.0f;

    // Boucle principale du jeu
    while (!WindowShouldClose()) {
        // Mise à jour de la position du joueur (exemple)
        if (IsKeyDown(KEY_RIGHT)) playerPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) playerPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) playerPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) playerPosition.y += 2.0f;

        // Mise à jour de la caméra
        camera.target = playerPosition;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);

        // Dessin de la carte
        for (int y = 0; y < mapHeight; y++) {
            for (int x = 0; x < mapWidth; x++) {
                Vector2 position = {(float)(x * tileSize), (float)(y * tileSize)};
                if (map[y][x] == 'G') {
                    DrawTexture(grassTexture, position.x, position.y, WHITE);
                } else if (map[y][x] == 'W') {
                    DrawTexture(waterTexture, position.x, position.y, WHITE);
                }
            }
        }

        // Dessin du personnage (simple rectangle)
        DrawRectangleV(playerPosition, (Vector2){tileSize, tileSize}, RED);

        EndMode2D();
        EndDrawing();
    }

    // Déchargement des textures
    UnloadTexture(grassTexture);
    UnloadTexture(waterTexture);

    // Fermeture de la fenêtre
    CloseWindow();

    return 0;
}
