struct Vector2
{
    float x;
    float y;
};

struct Vector3
{
    float x;
    float y;
    float z;
};

struct Vector2 projectPoint(struct Vector3 p, struct Vector3 cam, int w, int h, float f)
{
    // world -> camera
    struct Vector3 pc = {
        p.x - cam.x,
        p.y - cam.y,
        p.z - cam.z};

    // perspective
    struct Vector2 proj = {
        pc.x / pc.z,
        pc.y / pc.z};

    // screen
    struct Vector2 screen = {
        proj.x * f + w / 2,
        -proj.y * f + h / 2};

    return screen;
}