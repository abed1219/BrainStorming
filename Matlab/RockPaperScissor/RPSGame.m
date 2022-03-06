function RPSGame(duration)

Rounds = 1; %initial round
Pwins = 0; % Player wins counter
Cwins = 0; % Computer wins counter
Rcount=0; Pcount=0; Scount=0;
flag =0;
while (Rounds <= duration)
    fprintf('\nRound %d \n', Rounds);
    Rounds = Rounds+1; % Increase rounds number
    pause(0.8);
    o = 1; % ask repeatatively till user's choice is received.
    while o == 1
        close all;
        % get an option from the player
        Pmove = questdlg('Pick a move','Rock Paper Scissor','Rock','Paper','Scissor','Rock');
        % player moves cases
        switch Pmove
            case 'Rock'
                % Read Rock Image 
                Pimg = imread('rock.jpg');
                subplot(1,2,1); imshow(Pimg);
                title('Player picked Rock');
                Rcount = Rcount+1;
                o=0; % "Break"
            case 'Paper'
                % Read Paper Image 
                Pimg = imread('Paper.jpg');
                subplot(1,2,1); imshow(Pimg);
                title('Player picked Paper');
                Pcount = Pcount+1;
                o=0;
            case 'Scissor'
                % Read Scissor Image 
                Pimg = imread('Scissor.jpg');
                subplot(1,2,1); imshow(Pimg);
                title('Player picked Scissors');
                Scount=Scount+1;
                o=0;
            otherwise %ask again for the right input
              disp('Invalid option. pick again!');
        end
    end
    pause(0.3); 
    pause on;
    %initMove = randi(3); %generate a starting number(move) 
    %                                 Computer's choice, odds calculation
    Rp = Pcount/(Rcount+Pcount+Scount);
    Pp = (Pcount+Rcount)/(Rcount+Pcount+Scount);
    Sp = 1;
    %initial move (when player's moves history is empty)
%    if ((Pcount == 1 && Rcount==0 && Scount == 0)||(Pcount == 0 && Rcount==1 && Scount == 0)||(Pcount == 0 && Rcount==0 && Scount == 1))
%        flag = initMove; %1 rock , 2 paper ,3 scissor
%    end

    m = randi(2) - 1;
    if  m <= Rp % <= or < ?? initial move not valin with <
         Cimg = imread('rock.jpg');
         subplot(1,2,2); imshow(Cimg);
         title('Computer picked Rock')
         flag = 1;
    elseif m > Rp && m <= Pp  
        Cimg = imread('Paper.jpg');
        subplot(1,2,2); imshow(Cimg);
        title('Computer picked Paper')
        flag =2; 
    elseif (m > (Pp && m <= 1))  
        Cimg = imread('Scissor.jpg');
        subplot(1,2,2); imshow(Cimg);
        title('Computer picked Scissors')
        flag =3;
    end
    pause(0.5);
    %                                 All available possibilities
    %  Rock wins aginst scissors
    %  Rock vs flag = 3
    if strcmp(Pmove,'Rock') && flag == 3
        fprintf('You Won!\n');
        Pwins = Pwins + 1;
        h = msgbox('Congratulations!,You win','Success','custom',Pimg); 
        
        % Scissor v flag = 1
    elseif strcmp(Pmove,'Scissor') && flag == 1 
        fprintf('You Lost!\n');
        Cwins = Cwins + 1;
        h = msgbox('Computer wins','Loss','custom',Cimg);
        
        %  Scissors wins aginst paper
        %  Scissor v flag = 2
    elseif strcmp(Pmove,'Scissor') && flag == 2
        fprintf('You Won!\n');
        Pwins = Pwins + 1;
        h = msgbox('Congratulations!,You win','Success','custom',Pimg);
        
        %  Paper v flag = 3
    elseif strcmp(Pmove,'Paper') && flag == 3
        fprintf('You Lost!\n');
        Cwins = Cwins + 1;
        h = msgbox('Computer wins','Loss','custom',Cimg);
        
        %  Paper wins aginst rock
        %  Paper v flag = 1
    elseif strcmp(Pmove,'Paper') && flag == 1
        fprintf('You Won!\n');
        Pwins = Pwins + 1;
        h = msgbox('Congratulations!,You win','Success','custom',Pimg);
        
        %Paper wins aginst rock
        % Rock v flag = 2
    elseif strcmp(Pmove,'Rock') && flag == 2 
        fprintf('You Lost!\n');
        Cwins = Cwins + 1;
        h = msgbox('Computer wins','Loss','custom',Cimg);
        
    else % if round is Draw
        fprintf('its a draw!\n')
        h = msgbox('Its a Draw','Draw');
        Rounds = Rounds-1; % Replay the current round
    end
    pause(1.5)
    delete(h);
end
% show who won the game, and whats his winning score
if Pwins > Cwins
    fprintf('\n\n\nYou Won!!\n\n\n');
    disp("Winner's Score:");
    disp(Pwins);
else
    fprintf('\n\n\nYou Lost!\n\n\n');
end
end