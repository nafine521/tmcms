<?php
$z[0]=Array("field","",266,288);
$z[0][4]['name']="keywords";
$z[1]=Array("field","",326,378);
$z[1][4]['name']="description";
$z[1][4]['function']="html2text(@me)";
$z[2]=Array("field","",729,748);
$z[2][4]['name']="title";
$z[3]=Array("global","",749,775);
$z[3][4]['name']="cfg_webname";
$z[4]=Array("include","",2147,2182);
$z[4][4]['filename']="side.htm";
$z[5]=Array("include","",2223,2258);
$z[5][4]['filename']="head.htm";
$z[6]=Array("field","\r\n\r\nglobal \$dsql;\r\n\r\n\$typeid = @me;\r\n\r\n\$query = \"SELECT * FROM `#@__arctype` where id =\$typeid \";\r\n\r\n\$dsql->Execute('a', \$query);\r\n\r\n\$arctype = \$dsql->GetObject('a');\r\n\r\n@me = \$arctype->typeimg;\r\n\r\n",2376,2626);
$z[6][4]['name']="typeid";
$z[6][4]['runphp']="yes";
$z[7]=Array("include","",2721,2755);
$z[7][4]['filename']="nav.htm";
$z[8]=Array("field","",3121,3150);
$z[8][4]['name']="position";
$z[9]=Array("channel","\r\n            <li>\r\n                \r\n                <a href=\"[field:typelink/]\">[field:typename/]</a>\r\n            </li>\r\n        \r\n           ",3760,4045);
$z[9][4]['type']="son";
$z[9][4]['currentstyle']="<li class='hover'><a href='~typelink~'>~typename~</a> </li>";
$z[10]=Array("field","",4350,4369);
$z[10][4]['name']="title";
$z[11]=Array("productimagelist","\r\n                    <li style=\"position: relative; float: left; width: 510px;\">\r\n                        <a href=\"javascript:;\">\r\n                            <img src=\"[field:imgsrc/]\">\r\n                            <p class=\"text\" style=\"color:white\"></p>\r\n                        </a>\r\n                    </li>\r\n                ",4758,5137);
$z[12]=Array("productimagelist","\r\n                        <li class=\"[field:text/]\">\r\n                            <a href=\"javascript:;\">\r\n                                <img src=\"[field:imgsrc/]\">\r\n                            </a>\r\n                        </li>\r\n                    ",5557,5857);
$z[13]=Array("field","",6309,6327);
$z[13][4]['name']="body";
$z[14]=Array("include","",6668,6705);
$z[14][4]['filename']="footer.htm";

?>