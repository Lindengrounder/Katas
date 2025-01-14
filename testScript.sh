 #!/bin/bash         

echo "Запуск скрипта по созданию lvm массива"
#Инструкция для дисков:
#0 Delete previos VG group
vgdisplay
vgreduce --removemissing SIUSeRAIDGroup
vgremove SIUSeRAIDGroup
vgdisplay
#1 Стереть данные с обоих дисков массива командой 
mkfs -t ext4 /dev/sdb1
mkfs -t ext4 /dev/sdc1
wipefs -a /dev/sdb 
wipefs -a /dev/sdc
vgdisplay
#2 Создать раздел gpt командой: 
parted --script /dev/sdb mklabel gpt  
parted --script /dev/sdc mklabel gpt
vgdisplay
#3. Записать таблицу разделов из файла на диск командой: 
sfdisk /dev/sdb < /home/vmuser/Desktop/partition-tablesdb.txt 
sfdisk /dev/sdc < /home/vmuser/Desktop/partition-tablesdc.txt
vgdisplay
#4. Создаем физические разделы командой: 
pvcreate /dev/sdb1 
pvcreate /dev/sdc1
vgdisplay
#5. Создаем виртуальную группу разделов командой: 
vgcreate SIUSeRAIDGroup /dev/sdb1 /dev/sdc1
#6. Создаем логический раздел командой: 
lvcreate -l 100%FREE -n SIUSeRAIDVolume0 SIUSeRAIDGroup
#7. Форматируем созданный раздел в файловую систему ext4 и устанавливаем метку тома при помощи команды: 
mkfs.ext4 /dev/SIUSeRAIDGroup/SIUSeRAIDVolume0 -L SIUSData
#8. Монтируем новый диск. Создаем на диске при помощи команды mkdir папки var и вложенную в нее sius-video.
mkdir /media/vmuser/SIUSData #Create point of mount
mount -t ext4 /dev/SIUSeRAIDGroup/SIUSeRAIDVolume0 /media/vmuser/SIUSData 
mkdir /media/vmuser/SIUSData/video{0..10} #должна создать 11 папок от video0 до video10
#9. Вставляем диск в рекордер, перезагружаем. В контрольной панели SIUSe-IP12 форматируем диск.
chmod -R 777 /media/vmuser/SIUSData

cp /home/vmuser/Desktop/siusehd.xml /media/vmuser/SIUSData1/siusehd.xml
