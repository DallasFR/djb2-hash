# djb2-hash
Petit tools qui a pas de quoi casser 3 pattes à un canard, mais qui facilite la vie un peu.

Bah oué, parceque quand on fais des Hell's Gate (c'est cool le nom sonne bien) j'ai pas vus d'article qui explique comment hasher les fonctions genre :

Table.NtAllocateVirtualMemory.dwHash = 0xf5bd373480a6b89b;
if (!GetVxTableEntry(pLdrDataEntry->DllBase, pImageExportDirectory, le.NtAllocateVirtualMemory))
return 0x1;

Et, faut pas se mentir, c'est un peu galère à comprendre au début. Ducoup, j'ai fait un petit tools voir microcosmique tools de 10 lignes.
Ducoup dans notre Table.NtFunction.dwHash = 0x000 bah ici c'est le hash de la fonction NtFunction obtenus via djb2 mais ce hash on l'obtient via un tools externe (genre le mien).
Par exemple, si je veux ajouter NtWriteVirtualMemory, je vais devoir prendre le hash de celui-ci : 0x68a3c2ba486f0741

.\djb2_hash.exe NtWriteVirtualMemory
Et je peux donc ajouter :

Table.NtWriteVirtualMemory.dwHash = 0x68a3c2ba486f0741;
if (!GetVxTableEntry(pLdrDataEntry->DllBase, pImageExportDirectory, le.NtWaitForSingleObject))
return 0x1;

Aussi, faut pas oublier d'ajouter NtWriteVirtualMemory dans la struct _VX_TABLE et le tour est joué vous voilà un vrai 1337 :)

Biensur, les Hell's Gate ou la fonction c'est pas de moi c'est des big boss de vx-underground
