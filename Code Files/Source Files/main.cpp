/*Include source files*/
#include "login_page.cpp"

int main()
{
    int* scene = new int(0);

    Admin admin;

    while (*scene != -1)
    {
        // A switch case that will switch between the different scenes
        // present in the program by passing the pointer int to those
        // different scene functions where it'll change accordingly
        switch (*scene)
        {
            case 0: // Login page
                runLoginScreen(scene, &admin);
                break;
            /*
              .
              .
              .
              .
            */
        }
    }

    cout << "Thank you & bye!!";

    return 0;
}