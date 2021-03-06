/*
 * GDevelop Core
 * Copyright 2008-2016 Florian Rival (Florian.Rival@gmail.com). All rights
 * reserved. This project is released under the MIT License.
 */
#include "AllBuiltinExtensions.h"
#include "GDCore/Tools/Localization.h"

using namespace std;
namespace gd {

void GD_CORE_API BuiltinExtensionsImplementer::ImplementsNetworkExtension(
    gd::PlatformExtension& extension) {
  extension
      .SetExtensionInformation(
          "BuiltinNetwork",
          _("Basic internet features"),
          _("Built-in extension providing network features."),
          "Florian Rival",
          "Open source (MIT License)")
      .SetExtensionHelpPath("/all-features/network");

#if defined(GD_IDE_ONLY)
  extension
      .AddAction(
          "SendRequest",
          _("Send a request to a web page"),
          _("Send a request to the specified web page.\n\nPlease note that for "
            "the web games, the game must be hosted on the same host "
            "as specified below, except if the server is configured to answer "
            "to all requests (cross-domain requests)."),
          _("Send _PARAM3_ request to _PARAM0__PARAM1_ with body: _PARAM2_"),
          _("Network"),
          "res/actions/net24.png",
          "res/actions/net.png")
      .AddParameter("string", _("Host, with protocol"))
      .SetParameterLongDescription(
          _("Example: \"http://example.com/\"."))
      .AddParameter("string", _("Path"))
      .SetParameterLongDescription(_("Example: \"/user/123\" or \"/some-page.php\"."))
      .AddParameter("string", _("Request body content"))
      .AddParameter("string", _("Method: \"POST\" or \"GET\""), "", true)
      .SetParameterLongDescription(_("If empty, \"GET\" will be used."))
      .SetDefaultValue("\"GET\"")
      .AddParameter("string", _("Content type"), "", true)
      .SetParameterLongDescription(
          _("If empty, \"application/x-www-form-urlencoded\" will be used."))
      .AddParameter("scenevar", _("Reponse scene variable"), "", true)
      .SetParameterLongDescription(
          _("The response of the server will be stored, as a string, in this "
            "variable. If the server returns *JSON*, you may want to use the "
            "action \"Convert JSON to a scene variable\" afterwards, to "
            "explore the results with a *structure variable*."))
      .MarkAsComplex();

  extension
      .AddAction(
          "DownloadFile",
          _("Download a file"),
          _("Download a file from a web site"),
          _("Download file _PARAM1_ from _PARAM0_ under the name of _PARAM2_"),
          _("Network"),
          "res/actions/net24.png",
          "res/actions/net.png")
      .AddParameter("string", _("Host (for example : http://www.website.com)"))
      .AddParameter("string",
                    _("Path to file (for example : /folder/file.txt)"))
      .AddParameter("string", _("Save as"));

  extension
      .AddAction(
          "JSONToVariableStructure",
          _("Convert JSON to a scene variable"),
          _("Parse a JSON object and store it into a scene variable"),
          _("Parse JSON string _PARAM0_ and store it into variable _PARAM1_"),
          _("Network"),
          "res/actions/net24.png",
          "res/actions/net.png")
      .AddParameter("string", _("JSON string"))
      .AddParameter("scenevar", _("Variable where store the JSON object"))
      .MarkAsAdvanced();

  extension
      .AddAction("JSONToGlobalVariableStructure",
                 _("Convert JSON to global variable"),
                 _("Parse a JSON object and store it into a global variable"),
                 _("Parse JSON string _PARAM0_ and store it into global "
                   "variable _PARAM1_"),
                 _("Network"),
                 "res/actions/net24.png",
                 "res/actions/net.png")
      .AddParameter("string", _("JSON string"))
      .AddParameter("globalvar",
                    _("Global variable where store the JSON object"))
      .MarkAsAdvanced();

  extension
      .AddAction("JSONToObjectVariableStructure",
                 _("Convert JSON to object variable"),
                 _("Parse a JSON object and store it into an object variable"),
                 _("Parse JSON string _PARAM0_ and store it into variable "
                   "_PARAM2_ of _PARAM1_"),
                 _("Network"),
                 "res/actions/net24.png",
                 "res/actions/net.png")
      .AddParameter("string", _("JSON string"))
      .AddParameter("objectPtr", _("Object"))
      .AddParameter("objectvar",
                    _("Object variable where store the JSON object"))
      .MarkAsAdvanced();

  extension
      .AddStrExpression("ToJSON",
                        _("Convert scene variable to JSON"),
                        _("Convert a scene variable to JSON"),
                        _("Conversion"),
                        "res/conditions/toujours24.png")
      .AddParameter("scenevar", _("Scene variable to be stringified"));

  extension
      .AddStrExpression("GlobalVarToJSON",
                        _("Convert global variable to JSON"),
                        _("Convert a global variable to JSON"),
                        _("Conversion"),
                        "res/conditions/toujours24.png")
      .AddParameter("globalvar", _("The global variable to be stringified"));

  extension
      .AddStrExpression("ObjectVarToJSON",
                        _("Convert object variable to JSON"),
                        _("Convert an object variable to JSON"),
                        _("Conversion"),
                        "res/conditions/toujours24.png")
      .AddParameter("objectPtr", _("The object with the variable"))
      .AddParameter("objectvar", _("The object variable to be stringified"));
#endif
}

}  // namespace gd
