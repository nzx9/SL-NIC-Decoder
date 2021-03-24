# SL-NIC-Decoder
Find Gender and Birthday by NIC Number (Sri Lanka) [Lang: C++]

C++  program that can decode informations like gender and birthday, using Sri Lankan National Id Card Number.
This Program works for <b>both</b> old(9 digits + v) and new(12 digits) NIC numbers.
<hr/>
<h3>Info about NIC</h3>
<b>10 Character NIC | Ex: 987654321V</b>
<ul>
  <li>First 2 characters(98) give the last two digits of birth year(1900 + 98 = 1998)</li>
  <li>Next 3(765) characters give information about gender and birth month and day</li>
  <li>If value of 3rd character to 5th character is higher than 500 that means gender is female, if it less than 500 means gender is male</li>
  <li>If gender is female, have to substract 500 from 3rd character to 5th character(765 - 500), then take the month and day accoding to the number of days in each month(January: 31, February: 29, March: 31, April: 30, ...)</li>
</ul>

<b>12 Character NIC | Ex: 199876543210</b>
<ul>
  <li>First 4 characters(1998) give the birth year</li>
  <li>Next 3(765) characters give information about gender and birth month and day</li>
  <li>If value of 5th character to 8th character(765) is higher than 500 that means gender is female, if it less than 500 means gender is male</li>
  <li>If gender is female, have to substract 500 from value of 5th character to 8th chatacter(765 - 500), then take the month and day accoding to the number of days in each month(January: 31, February: 29, March: 31, April: 30, ...)</li>
</ul>

<h4>Pseudocode</h4>
<b>Algorithm NIC-Decoder(NIC)</b><br/>
<i>input: NIC, Output: Struct includes birthday and gender</i><br/>
<ol>
    <li>nic <- input NIC number(without v)</li>
    <li>if nic.length != 9 or nic.length != 12 exit and throw error "Wrong nic"</li>
    <li>if nic.length == 9 then year <- 1900 + str2int(nic[0:1]), temp <- nic[2:4] and goto step 5</li>
    <li>if nic.length == 12 the year <- str2int(nic[0:3]), temp <- nic[4:6] and goto step 5</li>
    <li>if temp > 500 then gender <- female else gender <- male</li>
    <li>if temp > 500 then temp <- temp - 500</li>
    <li>{month, day} <- monthAndDate(temp)</li>
    <li>return {{year, month, day}, gender}</li>
</ol>


## Other Implementations
For python implementation, please goto [krypto-i9/nic-exec](https://github.com/krypto-i9/nic-exec)
