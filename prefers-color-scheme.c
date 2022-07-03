#include <gio/gio.h>

int main () {
  g_autoptr (GError) error = NULL;
  g_autoptr (GVariant) result = NULL;
  g_autoptr (GVariant) inner_result = NULL;
  g_autoptr (GVariant) raw_color_scheme = NULL;

  GDBusProxy *settings_portal =
    g_dbus_proxy_new_for_bus_sync
      ( G_BUS_TYPE_SESSION
      , G_DBUS_PROXY_FLAGS_NONE
      , NULL
      , "org.freedesktop.portal.Desktop"
      , "/org/freedesktop/portal/desktop"
      , "org.freedesktop.portal.Settings"
      , NULL
      , &error
      );

  if (error) {
    g_error ("Settings portal not found: %s", error->message);

    return 1;
  }

  result =
    g_dbus_proxy_call_sync
      ( settings_portal
      , "Read"
      , g_variant_new ("(ss)" , "org.freedesktop.appearance" , "color-scheme")
      , G_DBUS_CALL_FLAGS_NONE
      , G_MAXINT
      , NULL
      , &error
      );
  
  if (error) {
    if ( error->domain == G_DBUS_ERROR
      && error->code == G_DBUS_ERROR_SERVICE_UNKNOWN
    ) {
      g_error ("It appears there is no portal available: %s", error->message);

      return 1;
    }
    
    if ( error->domain == G_DBUS_ERROR
      && error->code == G_DBUS_ERROR_UNKNOWN_METHOD
    ) {
      g_error ("It seems that your portal doesn't support this query: %s", error->message);

      return 1;
    }
    
    g_error ("Reading color-scheme setting from your portal failed: %s", error->message);

    return 1;
  }
  
  g_variant_get (result, "(v)", &inner_result);
  g_variant_get (inner_result, "v", &raw_color_scheme);
  
  switch (g_variant_get_uint32 (raw_color_scheme)) {
    case 1:
      g_print ("dark\n");
      break;
    // case 0:
    //   g_print ("light\n");
    //   break;
    default:
      g_print ("light\n");
      // g_print ("default\n");
  }
  
  return 0;
}
