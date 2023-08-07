/*Include source files*/
#include "login_page.cpp"
#include "admin_page.cpp"

int main()
{
    int* scene = new int(0);

    RenderWindow window(VideoMode(1600, 900), "HBM");
    window.setVerticalSyncEnabled(true);

    Admin admin;

    while (*scene != -1)
    {
        switch (*scene)
        {
            case 0: // Login page
                runLoginScreen(scene, &admin, &window);
                window.clear();
                break;
            case 1:
                runAdminPage(scene, &admin, &window);
                window.clear();
                break;
            /*
              .
              .
              .
              .
            */
        }
    }

    cout << "Thank      you & bye!!";

    return 0;
}